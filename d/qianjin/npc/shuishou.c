// beggar.c

inherit NPC;

void create()
{
        set_name("ˮ��", ({ "shuishou" }) );
        set("gender", "����" );
        set("age", 23);
        set("long", "һ�����ڰڰ����ӣ��Բ������ǧ��¥��ū\n");
        set("combat_exp", 100);
        set("str", 27);
        set("force", 200);
	set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 2);
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"ˮ������Ц��Ц��������֣�����������Ҫ��Ǯ��\n",
        }) );
        set("inquiry", ([
                "���ϰ˽�" : "Ŷ�����Ƕ�ס�ںɻ�����\n",
        ]) );
        carry_object("clone/cloth/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"����һ�����������Ŀ��ĵģ�");
        return 1;
}
