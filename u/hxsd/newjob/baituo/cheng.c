// ding.c �Ҷ�

inherit NPC;
#include <ansi.h>
int accept_object(object who, object ob);
int ask_job();

void create()
{
        set_name("�̹ܼ�", ({ "cheng laoban", "cheng", "laoban" }));
        set("age", 25);
        set("gender", "����");
        set("nickname", HIY"��ǧ��"NOR);
        set("title","����ɽׯ�ܼ�");
        set("long", "����һ�������������ˣ���������¶��ȴ�������ǽƻ������Ǵ�����\n");
        set("attitude", "peaceful");
        set("combat_exp", 20000);
        set("shen", -5000);

        set("str", 20);
        set("int", 12);
        set("con", 24);
        set("dex", 24);
        set("bac", 20);

        set("qi", 900);
        set("max_qi", 900);
        set("jingli", 600);
        set("max_jingli", 600);
        set("neili", 500);
        set("max_neili", 500);
        set("rank", "����");

        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60); 
        set_skill("parry", 60); 
	set_skill("literate", 90); 

//	        create_party("Ȩ����","����",1);

//      carry_object("/clone/misc/cloth")->wear();
//      carry_object(__DIR__"obj/tiecheng")->wield();

        set("inquiry", ([
                "job" : (: ask_job :),
        ]) );

        setup();
}


int ask_job()
{
        mapping party,quest;
        object me, ob;

        me = this_player();
        quest = __DIR__"jyquest"->query_quest();

         if( me->query("family/family_name") != "����ɽ��")
            {
                  message_vision("$N����$n���һ�������ɵ��Ӳ�����ծ��\n", this_object(), me);
                return 1;
            }
     
        if (me->query_temp("qljob") && me->query_temp("qljob") == 1)
        {
                command("hmm");
                command("say �ǲ��ǶԸ���Ĺ��������⣿�ߣ�");
                return 1;
        }

        else if (me->query_temp("qljob") && me->query_temp("qljob") == 4)
        {
                command("jump");
                command("say �ɵĺã���������ɽׯ�����磬��ȥЪЪ�ɣ�");
                write("��ľ���������.\n",);
                write("���Ǳ��������.\n",);
                me->add("potential", 80+random(180));
                me->add("combat_exp", 100+random(300));
                me->add("party/tasks", 2);
                me->delete_temp("qljob");
                me->delete_temp("subject");
                me->delete_temp("money");
                return 1;
        }

        else if ( me->query_condition("jyfail") )
        {
                command("say ����Ҫ���ʶ�Ҫ�������ֲ���ɱ�ˣ��һ���ô�������£�");
                command("say �㻹��ȥ�ɣ�ʡ�����ǰ���ɽׯ���������㶪���ˣ�");
                me->delete_temp("qljob");
                me->delete_temp("subject");
                me->delete_temp("money");
                return 1;
        }
        else if ( me->query_temp("qljob"))
        {
                command("say �����ʲ���Ǯ���ǲ���������ѽ��");
                return 1;
        }

        command("say " + quest["quest_1"] + "Ƿ���ǰ���ɽׯ" + chinese_number(quest["quest_2"]) + "�����ӣ���ȥҪ�����ɡ�");
        command("say ����Ƿ�����ã����Ǳ·ϻ���ֱ������(shouzhang)��");
        command("say ���" + quest["quest_1"] + "���Ų�������ɱ�������������ǰ���ɽׯ�����硣");

        me->set_temp("qljob", 1);
        me->set_temp("subject", quest["quest_1"]);
        me->set_temp("money", quest["quest_2"]);
        ob = new(__DIR__"qiandan");
        ob->set("long", "
        Ƿ��
" + quest["quest_1"] + "Ƿ����ɽׯ" + chinese_number(quest["quest_2"]) + "��������
��˵��ƾ������Ϊ֤��

        ���Ϻ�������ɽׯ\n");
        ob->move(me);
        return 1;
}

int accept_object(object who, object ob)
{
        mapping myfam;

        if (ob->query("money_id")) 
        {
                if (who->query_temp("qljob") && (who->query_temp("qljob") == 1))
                {
                        command("say ���Ǯ�Ҿ������ˣ�������Ļ�ȴû�����꣡");
                        command("say ������ȥ����");
//                        destruct(ob);
                        return 1;
                }
                else if (who->query_temp("qljob") && (who->query_temp("qljob") == 2 ||who->query_temp("qljob") == 5))
                {
                        command("say �Լ��ղ����ʻ������ң��㵱����˭��");
                        command("say ���Ǯ������Т���ҵģ����������ٽ��㡣");
//                        destruct(ob);
                        who->delete_temp("qljob");
                        who->delete_temp("subject");
                        who->delete_temp("money");
                        return 1;
                }
                else if (who->query_temp("qljob") && who->query_temp("qljob") == 3 && ob->value() >= (100 * who->query_temp("money")))
                {
                        command("say �������ɵ�ȷʵ������ȥ��Ϣ�ɡ�");
                        message_vision("�̹ܼ����ʵ��ϼ���һ�ʣ�Ȼ���Ǯ�Ž���Ǯ��\n", who);
                        message_vision("��ľ���������.\n", who);
                        message_vision("���Ǳ��������.\n", who);
                        who->add("potential", 60+random(60));
                        who->add("combat_exp", 80+random(80));
                        who->delete_temp("qljob");
                        who->delete_temp("subject");
                        who->delete_temp("money");
//                        destruct(ob);
                        return 1;
                }
                else if (who->query_temp("qljob") && who->query_temp("qljob") == 3 && ob->value() < (100 * who->query_temp("money")))
                {
                        command("say ��������ôһ��Ǯ�����������Ǯ�����˰ɣ�");
                        command("say �������ǻ�Ĳ��ͷ��ˡ�");
                        return 1;
                }
                else return notify_fail("��������ʦû���뵽���������֪ͨ��ʦ�ɡ�\n");
        }
        else
        {
                return notify_fail("����������ʲô?\n");
        }
}
