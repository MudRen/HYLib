 // scavenger.c
inherit NPC; 
void create()
{
        set_name("�����õ�", ({ "scavenger" }) );
        set("gender", "����" );
        set("age", 47);
        set("long", "����˲����Լ������ã�����Ҳ�������ò�����\n");
        set("combat_exp", 10);
        set("str", 27);
        set("neili", 30);
        set("max_neili", 30);
        set("force_factor", 1);
        setup();
        set("chat_chance", 20);
        set("chat_msg", ({
                "�����õ�ߺ�ȵ����ա��ơ��á��ġ�\n",
                "�����õ��������������֪��˵Щʲ�ᡣ\n",
                "�����õ�����׽ס�����ϵġ��ӣ�һ�Ųȵñ��ġ� \n",
                (: random_move :)
        }) );
        carry_object(__DIR__"obj/old_book");
        add_money("coin", 5);
} 
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + "��");
        return 1;
} 
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
        return 0;
} 
