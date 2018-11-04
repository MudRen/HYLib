//[lover 1999]
#include <ansi.h>
#define QUEST_LETTER __DIR__"quest"  
#define QUEST_NAME __DIR__"name"  
inherit NPC;
//inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name("���ϰ�",({"chen laoban","laoban"}));
        set("long","����һ�����������ͻ����˲Ƶ��ϰ�.\n");
        set("title", HIC"�ͻ�����"NOR);
        set("gender", "����");
        set("attitude", "friendly");
        set("age", 40);
        set("shen_type", 0);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);

        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 3000000);
        set("score", 10000);
        set("env/wimpy", 10000);
        set("inquiry", ([
                "����": "�����ڷ�����ô������Щ�����أ�����������! \n",
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
        if (ob->query("money_id"))
        {
               if(!who->query("quest") || ( ob->value() < 2000))
             {
                   message_vision("����ȱǮ�ã���л���ˣ�\n",who);
                   return 1;
             }
             else
             {
message_vision("���ϰ�̾�˿��������ðɣ�������������,��ȥ���������\n",who);
                   who->apply_condition("hxsd_busy",1+random(4));
                   who->apply_condition("menpai_busy",6);
                   who->set("quest",0);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   destruct(present("huo wu",who));
                   return 1;
             }
         }
return 0;
}

int give_quest()
{
        mapping quest ;
        mapping name ;

        object me,letter;
        int combatexp, timep, factor;

        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

        if((quest =  me->query("quest")))
               return notify_fail("�������б������\n");

      if ((int)me->query_condition("hxsd_busy"))  
            {
                      message_vision("���ϰ����$Nҡ��ҡͷ˵������²���,�Ȼ�����!\n", me);
                      return 1;
            }

       if(combatexp < 50000)
       {
message_vision("���ϰ��$N˵���㾭�鲻���������Ͳ���Ӵ��\n",me);
         return 0;
        }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("���ϰ��$N˵����ðѻ�������͵�ѽ��\n", me);
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                        return 0;
                }
        }
                if (((int)time() - (int)me->query("last_task_time")) < 1)
                 {
                   message_vision("���ϰ��$N˵���������Ҷ��е÷��ţ��㻹�ǵȻ������ɡ�\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("���ϰ��$N˵�����������ã�������պ���һ������Ҫ�ͳ�ȥ��\n",me);
}
        quest = QUEST_LETTER->query_quest();
        name = QUEST_NAME->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "�ѻ����͸���" + quest["quest"] + "��������������ˡ�\n" NOR);
        letter = new(__DIR__"letter");
        letter->set("name",name["quest"]);
        letter->move(me);
        message_vision("$N����$n����"HIG"��" + letter->query("name") + "����\n"NOR,this_object(),me);
        quest["quest_type"] = "�ѻ����͸�";
        quest["exp_bonus"] = random(100) + 80;
        quest["pot_bonus"] = random(100) + 60;
        quest["score"] = 2;
if ( quest["time"] <= 120)
{
quest["time"] = 200;
}
if (me->query("combat_exp") > 500000)
{
        quest["exp_bonus"] = random(10) + 5;
        quest["pot_bonus"] = random(10) + 5;
        quest["score"] = 2;
}
        me->set("tzjob",1);
        me->set_temp("tufei",0);
        me->set("quest", quest);
        me->set("task_time", (int)time() + timep);
        me->set("quest_factor", factor);
        me->set("last_task_time", time());
        return 1;
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

        tell_object(me, HIW "���ϰ�˵����\n��" + time + "��");

                return 1;
}
