// yahuan.c
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("��Ů", ({ "jinu","girl","ji" }) );
	set("gender", "Ů��" );
       set("str", 19);
	set("per", 27);
	set("age", 19);

	set("long",
		"һ����������ļ�Ů����������ᣬò���绨��\n"
		"��������ӿ��ˣ�\n");

	set("chat_chance", 3);
	set("chat_msg", ({
		"��Ů�������˵����������ô��������ѽ��\n",
		"��ŮС�����������ָ�ס�\n",
		"��Ů�������˵�������˽�������ɡ�\n",
	}));
	setup();
	carry_object(__DIR__"obj/silk_bra")->wear();
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"��Ҫ�\n");
        return 1;
}
 
