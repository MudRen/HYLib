// ding.c �Ҷ�

inherit NPC;
#include <ansi.h>
int accept_object(object who, object ob);
int ask_job();
int ask_fail();
string ask_fangqi();
string ask_job2();
string ask_fangqi2();
void create()
{
        set_name("�̹ܼ�", ({ "cheng laoban", "cheng", "laoban" }));
        set("age", 25);
        set("gender", "����");
        set("nickname", HIY"��ǧ��"NOR);
        set("title","����ɽׯ�ܼ�");
        set("long", "����һ�������������ˣ���������¶��ȴ�������ǽƻ������Ǵ�����\n");
        set("attitude", "peaceful");
        set("combat_exp", 5000000);
        set("shen", -5000);
set("no_get",1);
        set("str", 200);
        set("int", 42);
        set("con", 44);
        set("dex", 44);
        set("bac", 40);

        set("qi", 9000);
        set("max_qi", 9000);
        set("jingli", 600);
        set("max_jingli", 6000);
        set("neili", 11500);
        set("max_neili", 11500);

	set("combat_exp", 8500000);
	set("score", 200000);

	set_skill("force", 250);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike",170);
	set_skill("hand",170);
	set_skill("training",300);
	set_skill("staff", 250);
	set_skill("hamagong", 300);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 300);
	set_skill("hamashengong", 300);
	
	map_skill("strike", "hamashengong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("wield shengzhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "hand.diaoshou" :),                
        }) );
	create_family("����ɽ��",1, "��ܼ�");


        set("inquiry", ([
                "job" : (: ask_job :),
                "fangqi" : (: ask_fangqi :),
		 "work"   : (: ask_job2 :),
		 "����"   : (: ask_job2 :),
         "fangqi": (: ask_fangqi2 :),
         "����"  : (: ask_fangqi2 :),
                "ʧ��" : (: ask_fail() :),
                "fail" : (: ask_fail() :),
        ]) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 850);

        setup();
	carry_object("/d/baituo/obj/shenshezhang")->wield();
	carry_object("/clone/misc/cloth")->wear();

}



int ask_job()
{
        mapping party,quest;
        object me, ob;
int exp,pot;
        me = this_player();
        quest = __DIR__"jyquest"->query_quest();

         if( me->query("family/family_name") != "����ɽ��")
            {
                  message_vision("$N����$n���һ�������ɵ��Ӳ�����ծ��\n", this_object(), me);
                return 1;
            }
      if( (int)me->query_skill("hamagong",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N����$n˵:����û������,��Ȼ�������!\n", this_object(), me);
                      return 1;
            }     
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������û�����,�Ȼ�����!\n", this_object(), me);
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
          exp=330+random(350);
          pot=280+random(250);
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
                me->add("potential", pot);
                me->add("combat_exp", exp);
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
        me->apply_condition("menpai_busy",5);
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
int exp,pot;
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
          exp=250+random(100);
          pot=150+random(100);
	   tell_object(who,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
                        who->add("potential", pot);
                        who->add("combat_exp", exp);
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
string ask_fangqi()
{
         object me;
         me = this_player();
         if(me->query_temp("qljob")< 1)
         return "��û��������,������Ϲ����ʲ��?";
         me->delete_temp("qljob");
         me->delete_temp("subject");
         me->delete_temp("money");
         me->add("combat_exp",-150);
         me->add("potential",-80);
         me->apply_condition("jyfail",0);
//         return notify_fail("����������ʲô?\n");
//         command("û��ϵ,�´μ���Ŭ�� ��");
         return "û��ϵ,�´μ���Ŭ�� ��";
}


string ask_fangqi2()
{
         object me;
         me = this_player();
         if( me->query("family/family_name") != "����ɽ��")
       return "����������?";
         if( me->is_busy())
       return "����æ����!";
         if( me->is_fighting())
       return "����æ����!";

         if(!me->query_temp("bt2_song"))
         return "�ҽ���ȥ���߹���?";
         me->apply_condition("bt2_busy",5);
         me->delete_temp("bt2_song");
         return "û��ϵ,�´μ���Ŭ�� ��";
}

string ask_job2()
{     object wang,ob;
      object *team;
object obj;
          int i=0,count=0,minexp,maxexp;
      string where;
          wang =this_object();
          ob=this_player();
          
         if( ob->query("family/family_name") != "����ɽ��")
       return "����������?";
         if( ob->is_busy())
       return "����æ����!";
         if( ob->is_fighting())
       return "����æ����!";

  if ( (int)ob->query_condition("bt2_busy")>=1)  
       return "���Ҫ�����񣬵Ȼ�������";

	if( ((int)ob->query_skill("hamagong", 1)) < 10 )
		return "��ı����ڹ���δ���죡";
		          
  if (interactive(ob) && ob->query_temp("bt2_song") )  
       return "�ϴν�����������?";
          ob->set_temp("bt2_song","�����߳�");
          ob->apply_condition("bt2_busy",3);
          message_vision(HIY"\n$N�ӻ��֣�һ����ūץ��һ���߸��㡣\n"NOR,this_object());
          command("say ����Ұ������ߴ���ȥ����,���͵������߳���");
          ob->start_busy(2);
        obj = new(__DIR__"gongzi");
       obj->move(environment(ob));
        obj->set_temp("host",ob->query("id"));
        obj->set_leader(ob);
        message_vision("$N�϶���$n��\n",obj,ob);
          return "һ��ҪС���տ��������ı��ߡ���";   
}

int ask_fail()
{
        object me = this_player();
       
        if (me->query_temp("qljob")) {
                command("sigh");
                command("say �´β�׼��ʧ����Ȼׯ������!");
                me->apply_condition("menpai_busy",6);
                        me->delete_temp("qljob");
                        me->delete_temp("subject");
                        me->delete_temp("money");

                return 1;
                }
}
