// rascal.c

inherit NPC;

void create()
{
        set_name("��å", ({ "rascal" }) );
        set("gender", "����" );
        set("age", 24);
        set("long", "һ���������۵�С��å��\n");
        set("combat_exp", 20000);
        set("str", 27);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 5);
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
		  "��å�ߵ����ҿ�������ѩ�׵Ĵ��ȣ��Ҿ����ˡ������ġ�ඡ�\n",
		  "��å�ߵ����λ�ҹ�µ�..��..�ܣ�չת������..ɫ..�١�\n",
		  "��å����˯�����ڵ���˯�ˡ�\n",
        }) );
//      carry_object(__DIR__"obj/old_book");
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"��������һ�����кñ��ģ�");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"�������֣�С�ķ�����ǡ�\n");
        return 1;
}
 
