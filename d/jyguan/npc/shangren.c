// Living: /wizhome/sharkhome/jyguan/npc/shangren.c
// By Shark  10/08/1998

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��������", ({ "shang ren", "shang" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"���Ž��У���������,���ƴ�֮�ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 22000);
        set("str", 27);
        set("dex", 20);
        set("con", 23);
        set("int", 22);
	set("attitude", "peaceful");

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("sword", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);	

        set("chat_chance",10);
        set("chat_msg",({
     "������������ţ�����һ���Ҷ��Щ���ٸ������ٺ٣�׼�ܷ�����ˣ���\n",
        (: random_move :)
	}));


	setup();
//        carry_object(__DIR__"obj/xiyurobe")->wear();
        add_money("gold", 1);
}

