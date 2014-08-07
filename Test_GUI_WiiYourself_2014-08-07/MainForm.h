#pragma once

namespace Test_GUI_WiiYourself_20140807 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm の概要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Label_Title;
	private: System::Windows::Forms::Button^  Button_AppliEnd;
	protected:


	protected:

	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->Label_Title = (gcnew System::Windows::Forms::Label());
			this->Button_AppliEnd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Label_Title
			// 
			this->Label_Title->AutoSize = true;
			this->Label_Title->Location = System::Drawing::Point(13, 13);
			this->Label_Title->Name = L"Label_Title";
			this->Label_Title->Size = System::Drawing::Size(50, 12);
			this->Label_Title->TabIndex = 0;
			this->Label_Title->Text = L"ようこそ！";
			this->Label_Title->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// Button_AppliEnd
			// 
			this->Button_AppliEnd->Location = System::Drawing::Point(12, 226);
			this->Button_AppliEnd->Name = L"Button_AppliEnd";
			this->Button_AppliEnd->Size = System::Drawing::Size(75, 23);
			this->Button_AppliEnd->TabIndex = 1;
			this->Button_AppliEnd->Text = L"終了";
			this->Button_AppliEnd->UseVisualStyleBackColor = true;
			this->Button_AppliEnd->Click += gcnew System::EventHandler(this, &MainForm::Button_AppliEnd_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->Button_AppliEnd);
			this->Controls->Add(this->Label_Title);
			this->Name = L"MainForm";
			this->Text = L"Wiiリモコン動作テスト(GUI版)";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Button_AppliEnd_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	};
}
