inherit NPC;

void create()
{
        set_name("����", ({ "wei bing", "bing" }) );
        set("long",
"���Ǹ�����ִ��Ѳ�������������˭Ҳ�����׵��������ǡ�\n"
"�����Ҳ��Ҫ�������ǡ� \n");
        set("attitude", "heroism");
        set("pursuer", 1);
        set("vendetta_mark", "authority");
        set("str", 27);
        set("int", 26);
        set("con", 25);
         set("combat_exp", 200000+random(10000000));
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "�����ȵ�������ӣ�����������ӷ����������־͸���\n",
                "�����ȵ������޾��Ҿܲ������ˣ����ˣ�\n"
        }) );

        set_skill("unarmed", 660);
        set_skill("force", 660);
        set_skill("blade", 660);
        set_skill("dodge", 660);
        set_skill("parry", 660);
 
        set_temp("apply/attack", 650);
        set_temp("apply/defense", 650);
        set_temp("apply/armor", 650);
        set_temp("apply/damage", 630);

        set("neili", 10000); 
        set("max_neili", 500);
        set("jiali", 300);



        setup();

          carry_object("/d/city/obj/tiejia")->wear();
          carry_object("/d/city/obj/gangdao")->wield();
}


void init()
{
        object ob;
        ::init();
        if (!living(this_object()))     return;
        if (interactive(ob = this_player())){
                if (    (int)ob->query_condition("killer") ){
                        command("say �����������ү��ס�ˣ�ɱ�˷��������ӣ�\n");
                        ob->start_busy(2);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 0, ob);
                }
                if( this_player()->query_temp("illicit") ){
                        command("say ���ɣ������ӣ�\n");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 0, ob);
                }
        }
        add_action("do_kill","kill");
        add_action("do_kill","hit");
}
int do_kill(string arg)
{
        object ob;
        if (living(this_object()) && this_object()->id(arg)){
                command("say ���ܣ��ֵ��ǣ��ϣ�");
                if (ob=present("wu jiang",environment()))
                        ob->kill_ob(this_player());
                if (ob=present("guan bing",environment()))
                        ob->kill_ob(this_player());
        }
        return 0;
}
int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("killer", 500);
        kill_ob(me);
        return 1;
}

