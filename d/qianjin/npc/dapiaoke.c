
inherit NPC;

void create()
{
        set_name("���ο�", ({ "piaoke", "ke"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ���޽�Ŀ��ο�\n");
        set("combat_exp", 50000);
	set_skill("dodge", 200);
	set_skill("unarmed", 220);
	set("max_force",1000);
	set("force_factor",100);
        set("chat_chance", 3);
        set("chat_msg", ({
"���οͿ�Ц�����ã��������Ɑ��������������ʮ����\n",
        }) );
	
	setup();
	add_money("gold", 5);
        carry_object(__DIR__"obj/drinkcloth")->wear();
}

