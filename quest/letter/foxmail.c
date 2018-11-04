#include <ansi.h>
#define QUEST_LETTER(x) ("/quest/letter/qlist" + x)  
//����(lywin)2000/4/30�ո�ǰ��weixiaobao.c�ɴ���ʹ����ʤ�֣̿���Ī��֮��
inherit NPC;
inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name(HIW"��ʹ"NOR,({"foxmail"}));
        set("long","����һ��ר��Ϊ�����ŵ���ʹ��Ϊ�˻����ܸɣ������˳�֮Ϊ�����ꡱ��\n");

        set("title",HIG"����"NOR);
        set("gender", "����");
        set("attitude", "friendly");
         set("age", 40);
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 3000000);
        set("score", 10000);
        set("env/wimpy", 10000);
        set("inquiry", ([
                "����": "�����ڷ�����ô������Щ�ż�������������! \n",
        ]) );
        set("no_get", 1);

        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("cuff", 175);
        set_skill("parry", 170);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");

}

int accept_object(object who, object ob)
{
  if(who->query("combat_exp") > 100000)
        {
                message_vision("��ʹ��$N˵�������ǳ��������ˣ�����С������������ݣ���\n",who);
                return 0;
        }

        if ((int)who->query_condition("hxsd_busy"))  
            {
                    message_vision("$N����$nҡ��ҡͷ˵���������������²���,�Ȼ�����!\n", this_object(), who);
                    return 1;
            }

        if (ob->query("money_id"))
        {
             if(!who->query("quest") || ( ob->value() < 2000))
             {
                   message_vision("����ȱǮ�ã���л���ˣ�\n",who);
                   return 1;
             }
             else
             {
message_vision("��ʹ̾�˿��������ðɣ�������������,��ȥ���������\n",who);
                   who->set("quest",0);
                   who->delete("songxin");
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->apply_condition("hxsd_busy",1+random(4));
                   if (ob = present("xin", this_player()))
                   {
                   message_vision("��ʹ�������˻�ȥ��\n",who);
                   destruct(ob);     
                   }
                   return 1;
             }
         }
return 0;
}

int give_quest()
{
        mapping quest ;
        object me,letter,ob;
        int j, combatexp, timep,factor,num;
        string tag = "30000";
        string *levels = ({
                        "500",
                        "10000",
                        "30000",
                        "50000",
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
  if(combatexp < 500)
                {
message_vision("��ʹ����Ŀ���$Nһ��˵�������㱾�£���ɲ�Ҫ·Ҳ��ʶ�ã�\n",me);
                  return 0;
          }
  if(combatexp > 100000)
        {
                message_vision("��ʹ��$N˵�������ǳ��������ˣ�����С������������ݣ���\n",me);
                return 0;
        }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("��ʹ��$N˵����ð��Ű����͵�ѽ��\n", me);
                        return 0;
                }
        }
//   �˴��������ŵļ��ʱ�䡣�������ȴ����Խ�֮���ϣ�ʹ���ſ�����ʱ�ͣ�
             if (((int)time() - (int)me->query("last_task_time")) < 10)
                 {
                   message_vision("��ʹ��$N˵������û�ſ����ͣ��㻹�ǵȻ������ɡ�\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("��ʹ��$N˵�����������ã�������պ���һ���ż�Ҫ�ͳ�ȥ��\n",me);
}

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];

        quest = QUEST_LETTER(tag)->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "�����͸���" + quest["quest"] + "��������������ˡ�\n" NOR);
        message_vision("$N����$nһ���š�\n",this_object(),me);
        if (ob = present("xin", this_player()))
         {
             message_vision("��ʹ����ǰ�������˻�ȥ��\n",me);
             destruct(ob);
             letter = new(__DIR__"letter");
             letter->move(me);
             quest["quest_type"] = "�����͸�";
             quest["exp_bonus"] = quest["exp_bonus"];
             quest["pot_bonus"] = quest["pot_bonus"];
             quest["score"] = 0;

             me->set("quest", quest);
             me->set("songxin",1);
             me->set("task_time", (int)time() + timep);
             me->set("quest_factor", factor);
             me->set("last_task_time", time());
             return 1;     
         }
         else
         {
            letter = new(__DIR__"letter");
            letter->move(me);
            quest["quest_type"] = "�����͸�";
            quest["exp_bonus"] = quest["exp_bonus"];
            quest["pot_bonus"] = quest["pot_bonus"];
            quest["score"] = 0;

            me->set("quest", quest);
            me->set("songxin",1);
            me->set("task_time", (int)time() + timep);
            me->set("quest_factor", factor);
            me->set("last_task_time", time());
            return 1;
         }
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "��";

        else
                time = "";
        if(h)
                time += chinese_number(h) + "Сʱ";
        if(m)
                time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me, HIW "��ʹ˵����\n��" + time + "��");


                return 1;
}

