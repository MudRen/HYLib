// cainong.c

inherit NPC;

void create()
{
        set_name("��ũ", ({ "cainong", "nong" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һ��ɢ���ź����Ĳ�ũ��һ�������ھ�����̫����ɹ�����졣\n");
        set("attitude", "friendly");
        set("combat_exp", 250);
//	set("shen", 50);
	set("shen_type", 1);
        set("str", 20);
        set("dex", 18);
        set("con", 17);
        set("int", 13);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
"��ũ�˷ܵ�˵�������ҵĲ����ĺü��ˡ�\n",
"��ũһ����ʰ�Լ��ĵ��ӣ�һ�ߵ����������ڼ�ͷ��������ڳ�ͷ������������ͷ���ϡ� \n",
//                (: random_move :)
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
}

