// gao.c

inherit NPC;
void create()
{
       set_name("��ά", ({"wang wei", "wan"}));

set("long","��ά�ǽ���������ʫ�ˣ���˵�Ǹ����ӽ����ĸ��ˡ�\n");
       set("gender", "����");
       set("age", 52);
       set("title", "ʫ��");
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 85000);
        set_skill("unarmed", 25);
	set_skill("dodge", 15);
	set_skill("dagger", 35);
	set_skill("parry", 45);
set("inquiry", ([
"name": "�Ϸ�����,����ʲô����\n",
"here": "����������.\n",
]) );

	setup();
       add_money("silver", 5+random(5));
       // carry_object("/u/baiwt/xueshan/npc/obj/yandou")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

