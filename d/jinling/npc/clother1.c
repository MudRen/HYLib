// duangirl.c

inherit NPC;

void create()
{
	set_name("ѩ��", ({ "girl" }) );
	set("title", "������Ů��");
	set("gender", "Ů��" );
	set("age", 18);
	set("str", 12);
	set("per", 30);
	set("long", @LONG
����������Ů�����������������ʱ����ò������
���Ҳ��һ��������Ĳ��ٸ����ӵܶ���׷������
LONG
);
	set("combat_exp", 500);
       set("chat_chance", 1);
	set("chat_msg", ({
		"ѩ������������һЦ��\n",
		"ѩ��͵͵�����ſڿ���һ�ۡ�\n",
	}));

	set_skill("literate", 40);

	set("inquiry", ([
		"name" : "�Ҿ�����ѩ����",
		"here": "���ǲ÷��ѽ,���������·���",
		"��ҹ": "��......��ô����ô˵����",
		"�����": "�����ҵ����衣",
	]) );

	setup();
	
	carry_object(__DIR__"obj/pink_cloth")->wear();
}


