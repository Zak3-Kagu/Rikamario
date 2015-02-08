#ifndef _INPUT_H
#define _INPUT_H

namespace input{
	class InputBase{
	public:
		virtual void acquireState() = 0;
		virtual void end() = 0;
		/*  引数の値に関連したキーが押された場合trueを返す
		@param button 押されたキーコード
		*/
		virtual bool isPressed(const unsigned int& button) const = 0;
		/*  引数のキーが押されている場合trueを返す
		@param button 押されたキーコード
		*/
		virtual bool isBeingPressed(const unsigned int& button) const = 0;
		/*  引数のキーが離された場合trueを返す
		@param button 押されたキーコード
		*/
		virtual bool isReleased(const unsigned int& button) const = 0;
		InputBase() = default;
		virtual ~InputBase() = default;
	};
	class KeyBoard : public InputBase{
	private:
		// 1フレーム前の状態を格納するバッファ
		char pre_buffer[256];
		// 現在の状態を格納するバッファ
		char now_buffer[256];
	public:
		KeyBoard();
		~KeyBoard() = default;
		void acquireState() override;
		void end() override;
		inline bool isPressed(const unsigned int& key) const override { return (pre_buffer[key] == 0 && now_buffer[key] == 1) ? true : false; }
		inline bool isBeingPressed(const unsigned int& key) const override { return (now_buffer[key] == 1 && pre_buffer[key] == 1) ? true : false; }
		inline bool isReleased(const unsigned int& key) const override { return (pre_buffer[key] == 1 && now_buffer[key] == 0) ? true : false; }
	};
	class Mouse : public InputBase{
	private:
		int x = 0, y = 0;
		unsigned int pre_buffer = 0;
		unsigned int now_buffer = 0;
	public:
		~Mouse() = default;
		void acquireState() override;
		inline bool isPressed(const unsigned int& button) const override { return (bool)(!(pre_buffer&button) && (now_buffer&button)); }
		inline bool isBeingPressed(const unsigned int& button) const override { return (bool)((now_buffer&button) && (pre_buffer&button)); }
		inline bool isReleased(const unsigned int& button) const override { return (bool)((pre_buffer&button) && !(now_buffer&button)); }
		inline const int& getXPosition() const{ return x; }
		inline const int& getYPosition() const{ return y; }
		void end() override;
	};

}

#endif