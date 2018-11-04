//[lover 1999]
#include <ansi.h>
#define QUEST_LETTER __DIR__"quest"  
inherit NPC;
//inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name("���ưﳤ��",({"tiezhang jobshi","jobshi"}));
        set("long","����һ�����ư︺����Ȱ����ĳ���.\n");
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
                "����": "�����ڷ�����ô������ЩȰ���飬����������! \n",
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
message_vision("���ưﳤ��̾�˿��������ðɣ�������������,��ȥ���������\n",who);
                   who->apply_condition("menpai_busy",8);
                   who->apply_condition("hxsd_busy",8);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
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
        if(me->query("quest"))
            {
                      message_vision("���ưﳤ�϶���$Nҡ��ҡͷ˵�������ڻ��б������!\n", me);
                      return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("���ưﳤ�϶���$Nҡ��ҡͷ˵����Ȼ�����!\n", me);
                      return 1;
            }
if (present("xin",me))
            {
                      message_vision("���ưﳤ�϶���$Nҡ��ҡͷ˵�����Ȱ����ϵ����͵���˵!\n", me);
                      return 1;
            }

      if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("���ưﳤ�϶���$Nҡ��ҡͷ˵������û������,��Ȼ�����!\n", me);
                      return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("���ưﳤ�϶���$Nҡ��ҡͷ˵����Ȼ�����!\n", me);
                      return 1;
            }
      if ((int)me->query_condition("hxsd_busy"))  
            {
                      message_vision("���ưﳤ�϶���$Nҡ��ҡͷ˵������²���,�Ȼ�����!\n", me);
                      return 1;
            }


//   if((int)me->query("potential") > (500+(int)me->query("combat_exp")/1000))
//{
// /message_vision("���ưﳤ�϶�$N˵���������Ǳ��̫���ˣ��Ҳ��ܸ������񣡡�\n",me);
//  return 1;
//}
      if( me->query("family/family_name") != "���ư�")
            {
                message_vision("$N����$n���һ�������ɵ��Ӳ�����Ȱ���飡\n", this_object(), me);
                return 1;
            }
      if( (int)me->query_skill("guiyuan-tunafa",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
       if(combatexp < 80000)
       {
message_vision("���ưﳤ�϶�$N˵���㾭�鲻���������Ͳ���Ӵ��\n",me);
         return 0;
        }
     if(me->is_busy())
        return notify_fail("��������æ��\n");
     if (me->is_fighting()) 
        return notify_fail("���������������!\n");

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("���ưﳤ�϶�$N˵����ð�Ȱ��������͵�ѽ��\n", me);
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                        return 0;
                }
        }
                if (((int)time() - (int)me->query("last_task_time")) < 1)
                 {
                   message_vision("���ưﳤ�϶�$N˵���������Ҷ��е÷��ţ��㻹�ǵȻ������ɡ�\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("���ưﳤ�϶�$N˵�����������ã�������պ���һ��Ȱ����Ҫ�ͳ�ȥ��\n",me);
}
        quest = QUEST_LETTER->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "��Ȱ�����͸���" + quest["quest"] + "��������������ˡ�\n" NOR);
        message_vision("$N����$nһ��Ȱ���顣\n",this_object(),me);
        letter = new(__DIR__"letter");
        letter->move(me);
        quest["quest_type"] = "��Ȱ�����͸�";
//        quest["exp_bonus"]=quest["exp_bonus"]+ 100;
//        quest["pot_bonus"]=quest["pot_bonus"]+ 50;
        quest["exp_bonus"] = random(320) + 100;
        quest["pot_bonus"] = random(260) + 50;
        quest["score"] = 0;
me->apply_condition("menpai_busy",9);
me->apply_condition("hxsd_busy",9);
        me->set("tzjob",2);
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

        tell_object(me, HIW "���ưﳤ��˵����\n��" + time + "��");

                return 1;
}
