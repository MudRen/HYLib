// beggar.c

inherit NPC;

void create()
{
        set_name("����", ({ "huajiang" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һ���������ڽ�������԰�Ļ���\n");
        set("combat_exp", 100);
        set("str", 27);
        set("force", 200);
	set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 2);
        set("chat_chance", 1);
        set("chat_msg", ({
"�������𻨺���С�ĵ�����Ʒĵ���Ͻ�ˮ\n",
                (: random_move :)
        }) );
        set("inquiry", ([
                "���ϰ˽�" : "Ŷ�����Ƕ�ס�ںɻ�����\n",
		"����ѩ" : "������������հǳ��ˣ�\n",
		"xue" : "��������ĺ����࣬���Լ���������綼���ܼ���\n",
        ]) );
        setup();
        carry_object("clone/cloth/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"����һ�����������Ŀ��ĵģ�");
        return 1;
}
