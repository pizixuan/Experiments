package com.cloud.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.res.Resources;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.lang.reflect.Array;

public class MainActivity extends AppCompatActivity {

    private EditText user, recipent,sender, subject, text;
    private Button login, send;
    private TextView sigh;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        user = (EditText) findViewById(R.id.user);
        recipent = (EditText) findViewById(R.id.recipient);
        sender = (EditText) findViewById(R.id.sender);
        subject = (EditText) findViewById(R.id.subject);
        text = (EditText) findViewById(R.id.text);
        login = (Button) findViewById(R.id.login);
        send = (Button) findViewById(R.id.send);
        sigh = (TextView) findViewById(R.id.sigh);

        // 初始为不可编辑
        changeEditTextState(recipent);
        changeEditTextState(sender);
        changeEditTextState(text);
        changeEditTextState(subject);
        changeButtonState(send);

        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (user.getText().toString().equals("")) {
                    Toast.makeText(MainActivity.this, "请输入账号", Toast.LENGTH_SHORT).show();
                }
                else {
                    String[] userData = getResources().getStringArray(R.array.user_data);
                    for (String userdata : userData) {
                        // 登录成功
                        if (user.getText().toString().equals(userdata)) {
                            Toast.makeText(MainActivity.this, "登录成功", Toast.LENGTH_SHORT).show();
                            sender.setText(new StringBuilder("发件人: ").append(user.getText().toString()).append("@nchu.edu.cn"));
//                        text.setText(new StringBuilder(text.getText().toString()).append("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t签名：").append(user.getText().toString()));
                            sigh.setText(new StringBuilder(sigh.getText().toString()).append(user.getText().toString()));
                            // 修改状态
                            changeEditTextState(recipent);
                            changeEditTextState(subject);
                            changeEditTextState(text);
                            changeButtonState(send);
                            changeButtonState(login);
                        }
                    }
                    if (login.isEnabled())
                        Toast.makeText(MainActivity.this, user.getText().toString() + "用户不存在!", Toast.LENGTH_SHORT).show();
                }
            }
        });

        send.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                if (recipent.getText().toString().equals(""))
                    Toast.makeText(MainActivity.this, "收件人不得为空", Toast.LENGTH_SHORT).show();
                else {
                    Toast.makeText(MainActivity.this, new StringBuilder("正在向").append(recipent.getText().toString()).append("发送邮件..."), Toast.LENGTH_LONG).show();
                    Toast.makeText(MainActivity.this, "邮件发送成功", Toast.LENGTH_SHORT).show();
                }
            }
        });


        recipent.setOnFocusChangeListener(new android.view.View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View v, boolean hasFocus) {
                if (hasFocus) {
                    if (!recipent.getText().toString().equals(""))
                        recipent.setText(recipent.getText().toString().substring(5, recipent.length()));
                } else {
                    if (!recipent.getText().toString().equals(""))
                        recipent.setText(new StringBuilder("收件人: ").append(recipent.getText().toString()));
                }
            }
        });

        subject.setOnFocusChangeListener(new android.view.View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View v, boolean hasFocus) {
                if (hasFocus) {
                    if (!subject.getText().toString().equals(""))
                        subject.setText(subject.getText().toString().substring(4, subject.length()));
                } else {
                    if (!subject.getText().toString().equals(""))
                        subject.setText(new StringBuilder("主题: ").append(subject.getText().toString()));
                }
            }
        });
    }

    protected void changeEditTextState(EditText editText) {
        if (editText.isEnabled())
            editText.setEnabled(false);
        else
            editText.setEnabled(true);
    }

    protected void changeButtonState(Button button) {
        if (button.isEnabled())
            button.setEnabled(false);
        else
            button.setEnabled(true);
    }
}