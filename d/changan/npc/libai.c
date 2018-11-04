inherit NPC;
void create()
{
        set_name("���", ({ "li bai", "li" }));
        set("long", "̫�׾�ʿ�����������������ڡ�\n");
        set("gender", "����");
        set("age", 65);
        set_skill("literate", 300);
        set("max_jing",220);
        set_skill("taoism", 300);
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_temp("apply/attack", 280);
        set_temp("apply/defense", 280);
        set_temp("apply/damage", 200);
        set("combat_exp", 1000000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_learn","learn");
        add_action("do_learn","xue");
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
        int learn;
        learn=who->query_skill("literate",1);
        learn= learn?learn*10:500;
        if( !who->query_temp("mark/��") ) {
                if( ob->value() >= learn ) {
                        say(this_object()->name()+"���˵�ͷ��˵�����ܺã��ӽ���������ʱ�����������йض���ʶ\n"
                                "                      ��(literate)���κ����⡣\n");
                        who->add_temp("mark/��", ob->value()/10);
                        return 1;
                } else {
                        say(this_object()->name()+"˵������ĳ��ⲻ������Ǯ�����û�ȥ�ɡ�\n");
                        return 0;
                }
        } else if(ob->value()){
                say(this_object()->name()+"���˵�ͷ��˵����Ŷ�������������ĵ�ѧ�������ǲ�������ú�Ŭ��\n"
                        "                      �����ض�ǰ;������л�ˡ�\n");
                        who->add_temp("mark/��", ob->value()/10);
        }
        return 1;
}
int do_learn(string arg)
{
        string skill, teacher;
        object me,ob,room;
        int learn;
        int master_skill, my_skill, gin_cost, my_combat_exp,grade;
        me=this_player();
        ob=this_object();
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
        if(!arg || arg=="?" || arg=="/?")
                return notify_fail("ָ���ʽ��learn <ĳ��> <����>\tlearn <����> from <ĳ��>\n");
        if ((sscanf(arg, "%s from %s", skill,teacher)!=2 ))
                if ((sscanf(arg, "%s %s", teacher, skill)!=2 ))
                        return notify_fail("ָ���ʽ��learn <ĳ��> <����>\tlearn <����> from <ĳ��>\n");
        if (!ob->id(teacher))   return 0;
        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");
        if (me->query_skill("literate",1)<199)
               return notify_fail("�㻹���ȵ������ط�ѧ�ɡ�\n");
        if( !living(ob) )
                return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
        learn=me->query_skill("literate",1);
        if( !me->query_temp("mark/��") || me->query_temp("mark/��")<learn){
                command("say �ף�"+me->name()+"���Ҳ��ǵ��չ������ѧ����....\n");
                return 0;
        }
        if (!learn)     learn=10;
        if (skill!="literate")
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");
        if (! room=find_object(ob->query("startroom")))
                room=load_object(ob->query("startroom"));
        if (room!=environment()){
                command("say �ҳ�������£����һ�ȥ��˵�ɣ�");
                return 1;
        }
        if (ob->query("env/no_teach")){
                command("say �ҽ������ˣ���Ҫȥ��Ϣ�ˣ�");
                return 1;
        }
        my_skill = me->query_skill(skill, 1);
        master_skill = ob->query_skill(skill, 1);
        if( my_skill >= master_skill )
                return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");
        gin_cost = 150 / (int)me->query_int() + 1;
        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }
        printf("����%s����йء�%s�������ʡ�\n", ob->name(), to_chinese(skill));
        if( (int)ob->query("jing") > gin_cost/10 + 1 )
        {
                ob->receive_damage("jing", gin_cost/10+1);
        }
        else
        {
                write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
                ob->set("env/no_teach",1);
                call_out("do_sleep",1,ob);
                return 1;
        }
                
        my_combat_exp = (int)me->query("combat_exp");
        if(my_combat_exp < 50000)
                grade = 1;
        else if(my_combat_exp < 100000)
                grade = 3;
        else if(my_combat_exp < 500000)
                grade = 7;
        else
                grade = 13;
        if ( grade < 1 )
                grade = 1;
        if((int)me->query("jing") > gin_cost+20 )
        {
                printf("������%s��ָ�����ƺ���Щ�ĵá�\n", ob->name());
                me->improve_skill(skill, grade * (10 + random((int)me->query_int() - 9)));
        }
        else
        {
                write("�����̫���ˣ����ʲôҲû��ѧ����\n");
                return 1;
        }
      if (gin_cost<1) gin_cost=1;
        me->receive_damage("jing", gin_cost );
        me->add_temp("mark/��", -learn);
        return 1;
}
int do_sleep(object ob)
{
        object room;
        if (!ob)        return  0;
        message("vision",ob->name()+"���˸���Ƿ�������۾����ط�˯��ȥ�ˡ�\n",environment(ob));
        if (!room=find_object("/d/changan/shuyan2"))
                room=load_object("/d/changan/shuyuan2");
        ob->move(room);
        command("sleep");
        call_out("do_back",20,ob);
        return 1;
}
int do_back(object ob)
{
        object room;
        if (!ob)        return 0;
        if (!living(ob)){
                remove_call_out("do_back");
                call_out("do_back",10,ob);
        }
        ob->delete("short");
        ob->delete("env");
        if (!room=find_object(ob->query("startroom")))
                room=load_object(ob->query("startroom"));
        ob->move(room);
        message("vision",ob->name()+"������������΢Ц�����˹�����\n",room);
        return 1;
}
int return_home(object home)
{
        if( !environment()
        ||      environment()==home )
                return 1;
        // Are we able to leave?
        if( !living(this_object())
        ||      is_fighting()
        ||      !mapp(environment()->query("exits")) ){
           call_out("return_home",10,home);
           return 1;
         }
        // Leave for home now.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());
        return move(home);
}

