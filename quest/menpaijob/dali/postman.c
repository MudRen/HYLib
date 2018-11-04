//[lover 1999]
#include <ansi.h>
#define QUEST_LETTER __DIR__"quest"  
inherit NPC;
//inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name("������",({"dali jiangjun","jiangjun"}));
        set("long","����һ������μҸ����;����Ľ�������������ż���Χ�ţ���������ü���������ӡ�\n");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");
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
        if (ob->query("money_id"))
        {
               if(!who->query("quest") || ( ob->value() < 5000))
             {
                   message_vision("����ȱǮ�ã���л���ˣ�\n",who);
                   return 1;
             }
             else
             {
message_vision("������̾�˿��������ðɣ�������������,��ȥ���������\n",who);
                   who->apply_condition("dali_busy",6);
                   who->apply_condition("hxsd_busy",6);
                   who->set("quest",0);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   destruct(present("xin",who));
                   return 1;
             }
         }
return 0;
}

int give_quest()
{
        mapping quest ;
        object me,letter;
        int combatexp, timep, factor;

        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

    if(me->is_busy())
        return notify_fail("��������æ��\n");
     if (me->is_fighting()) 
        return notify_fail("���������������!\n");
        if(me->query("quest"))
            {
                      message_vision("����������$Nҡ��ҡͷ˵�������ڻ��б������!\n", me);
                      return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("����������$Nҡ��ҡͷ˵����Ȼ�����!\n", me);
                      return 1;
            }

      if ((int)me->query_condition("dali_busy"))  
            {
                      message_vision("����������$Nҡ��ҡͷ˵������²���,�Ȼ�����!\n", me);
                      return 1;
            }
if (present("xin",me))
            {
                      message_vision("����������$Nҡ��ҡͷ˵�����Ȱ����ϵ����͵���˵!\n", me);
                      return 1;
            }

      if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("����������$Nҡ��ҡͷ˵������û������,��Ȼ�����!\n", me);
                      return 1;
            }

      if ((int)me->query_condition("hxsd_busy"))  
            {
                      message_vision("����������$Nҡ��ҡͷ˵������²���,�Ȼ�����!\n", me);
                      return 1;
            }

      if( me->query("family/family_name") != "����μ�")
            {
                message_vision("$N����$n���һ�������ɵ��Ӳ����;����ż���\n", this_object(), me);
                return 1;
            }
      if( (int)me->query_skill("kurong-changong",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }

       if(combatexp < 80000)
       {
message_vision("��������$N˵���㾭�鲻���������Ͳ���Ӵ��\n",me);
         return 0;
        }

   if((int)me->query("potential") - (int)me->query("learned_points") > 100000)
{
message_vision("��������$N˵���������Ǳ��̫���ˣ��Ҳ��ܸ������񣡡�\n",me);
  return 1;
}
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("��������$N˵����ð��Ű����͵�ѽ��\n", me);
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                        return 0;
                }
        }
                if (((int)time() - (int)me->query("last_task_time")) < 1)
                 {
                   message_vision("��������$N˵���������Ҷ��е÷��ţ��㻹�ǵȻ������ɡ�\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("��������$N˵�����������ã�������պ���һ�������ż�Ҫ�ͳ�ȥ��\n",me);
}
        quest = QUEST_LETTER->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "�����͸���" + quest["quest"] + "��������������ˡ�\n" NOR);
        message_vision("$N����$nһ���š�\n",this_object(),me);
        letter = new(__DIR__"letter");
        letter->move(me);
        quest["quest_type"] = "�����͸�";
//        quest["exp_bonus"]=quest["exp_bonus"]+ 100;
//        quest["pot_bonus"]=quest["pot_bonus"]+ 50;
        quest["exp_bonus"] = random(320) + 100;
        quest["pot_bonus"] = random(260) + 50;
//        if (me->query("combat_exp")<1000000)
//        {
//        quest["exp_bonus"]=quest["exp_bonus"]+ 100;
//        quest["pot_bonus"]=quest["pot_bonus"]+ 50;
//        }

        quest["score"] = 5;
me->apply_condition("menpai_busy",7);
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

        tell_object(me, HIW "������˵����\n��" + time + "��");

                return 1;
}
