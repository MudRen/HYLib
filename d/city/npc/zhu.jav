// zhu.c ����

inherit NPC;
inherit F_DEALER;

string ask_buy();
void create()
{
        set_name("����", ({ "zhu xi", "zhu" }));
        set("long",
"����������Ϊ������һ����ѧ�ң��������īˮ�Ⱥ���Ҫ�\n");
        set("gender", "����");
        set("age", 65);
        set_skill("literate", 300);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
        "����": (:ask_buy:),
        "��" : "��!�鵽��ʱ�����١�",
        "����":"�裿�㲻���ҵ��������㣿��!",
        ]));
        set("vendor_goods", ({
                __DIR__"obj/lbook1",
                __DIR__"obj/lbook2",
                __DIR__"obj/lbook3"
        }));
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "����˵��������֮�£�Ī������������֮����Ī��������\n",
                "����˵���������ˣ�С�������ɣ����������δ������֮��\n",
                "����˵������ѧ֮�����������¡���������ֹ�����ơ� \n",
                "����˵����������֪���������ģ�������ң��ι�ƽ���¡�\n",
        }) );
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
                return 0;
        ob->add_temp("mark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        object me = this_player();
        if (!(int)who->query_temp("mark/��"))
                who->set_temp("mark/��", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
                who->add_temp("mark/��", ob->value() / 50);
        if( me->query_skill("literate", 1) > 21){
        tell_object(me,
"����������һ�����Ļ�֪ʶ,Ҳ�����Լ����������ˡ�\n");
        return 1;}
                return 1;
         }
}

string ask_buy()
{
//      int i;
        return "������в��ٶ����˱ض�����Ӵ!\n";
//        i = (int)me->query_temp("ask_book");
}

void init()
{
        object me = this_player();
        add_action("do_list","list");
        if( me->query_skill("literate", 1) > 21)
        add_action("do_buy", "buy");
        return ;
}
