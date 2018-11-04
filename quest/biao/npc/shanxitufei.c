//gemini����2000.4.4
#include <ansi.h>
#define QUEST_DUO "/u/zzt/npc/questduo"
inherit NPC;

int time_period(int timep, object me);

void create()
{
  set_name("ɽ������", ({ "shanxi tufei", "tufei",}));
  set("title","");
  set("long",
               "ɽ������ר�Ÿ���ɱ����֯������Ҵ򽻵���\n");
  set("gender", "����");
  set("age", 30);
  set("attitude", "peaceful");
  set("shen_type", -1);
  set("str", 30);
  set("int", 23);
  set("con", 24);
  set("dex", 28);
  set("per",30);
  
  set("max_qi", 800);
  set("max_jing", 800);
  set("neili", 800);
  set("max_neili", 800);
  set("combat_exp", 500000);
  set("shen", 500);
  
  set_skill("force",150);
  set_skill("parry",160);
  set_skill("dodge",150);
  set_skill("sword",150);
  set_skill("unarmed",160);
  
  setup();
  carry_object("/d/city/obj/gangjian")->wield();
  carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
  add_action("give_quest", "quest"); 
   add_action("do_kill", "kill"); 
   add_action("do_fight", "fight");
}

int do_kill(string arg)
{
        object who = this_player();
        object me = this_object();

        if(!arg || present(arg,environment(me))!=me) return 0;

        message_vision (HIR"$N��¶�׹⣬�����Ӷ���ɱ����\n"NOR,who);
        call_out("no_kill",2,who,me);
        return 1;
} 
int do_fight(string arg)
{
        object who = this_player();
        object me = this_object();

        if(!arg || present(arg,environment(me))!=me) return 0;

        message_vision (HIW"ɽ������˵����������Ҵ���ȥ��Ӯ��ѩ��˵����\n"NOR,who);
        call_out("no_fight",2,who,me);
        return 1;
}



int give_quest()
{
  mapping quest,skl,hp_status,skl_p;
  object ob,me,ob1;
  int i,combatexp,timep,num,max_skl;
  string *sname,*sname_p;

  me = this_player();
  if (me->query("quest") && (int)time() < me->query("task_time")) return 0;
 
  combatexp = (int)(me->query("combat_exp"));
  
  if(combatexp < 10000)
    {
      message_vision("ɽ�����˶���$N����˵��������ֻ���㣬���������������ɡ�\n",me); 
      return 0;
    }
  
     if(combatexp > 500000)
{
      message_vision("ɽ�����˶���$N����˵�������������ָ��֣����Ҷ����������Ͷ���ܡ�\n",me); 
return 0;
}
  message_vision("ɽ�����˶�$N˵���㸽��������\n",me);
  
  quest = QUEST_DUO->query_quest();
  timep = random(100) + 300;
  time_period(timep, me);
  tell_object(me, "��ȥ���ڽٹ����������ڡ�" + quest["short"]
              + "������ȥ�ɣ�\n" NOR);
  quest["quest_type"] = "����";
  quest["quest"] =quest["short"]; 
  quest["exp_bonus"] = random(60) + 80;
  quest["pot_bonus"] = random(40) + 50;
  quest["score"] = 0;
  command("chat �ºڷ��ҹ��ɱ�˷Ż��졣");
  me->set("quest", quest);
  me->set_temp("questduo",1);
  me->set("task_time", (int)time() + timep);
  me->set("quest_factor",10);

  // setup the target.

  num = random(40);
  if (num < 10) ob = new("/u/zzt/npc/biaotou1");
  else if (num < 20) ob = new("/u/zzt/npc/biaotou2");
  else if (num < 30) ob = new("/u/zzt/npc/biaotou3");
  else ob = new("/u/zzt/npc/biaotou4");
  
  hp_status = me->query_entire_dbase();
  ob->set("max_qi",    hp_status["max_qi"]);
  ob->set("eff_qi",    hp_status["eff_qi"]);
  ob->set("qi",        hp_status["qi"]);
  ob->set("max_jing",  hp_status["max_jing"]);
  ob->set("eff_jing",  hp_status["eff_jing"]);
  ob->set("jing",      hp_status["jing"]);
  ob->set("max_neili", hp_status["max_neili"]);
  ob->set("neili",     hp_status["neili"]);
   ob->set("combat_exp",hp_status["combat_exp"]);

  skl = ob->query_skills();
  if(!sizeof(skl))
    return notify_fail("Ŀ�����ó����뱨���ѩ��\n");
  
  skl_p = me->query_skills();
  if(!sizeof(skl_p))
    return notify_fail("��ûѧ�κμ��ܣ�����ȥ������\n");
  
  max_skl = 0;
  sname_p  = sort_array( keys(skl_p), (: strcmp :) );

  for(i=0; i<sizeof(skl_p); i++)
    {
      if(skl_p[sname_p[i]] > max_skl) max_skl = skl_p[sname_p[i]];
    }

  max_skl -= 5;

  if(max_skl < 0) max_skl = 10;

  sname  = sort_array( keys(skl), (: strcmp :) );
  for(i=0; i<sizeof(skl); i++)
    {
     if(sname[i]=="literate")i++;
	 ob->set_skill(sname[i],max_skl);
    }
  
  ob1 = new("/u/zzt/npc/hongbiao");
  ob->set("long",ob->query("long") + "\n����" + me->query("name") +
           "(" + me->query("id") + ")" + "��Ŀ�ꡣ\n");
  ob->set("player",me->query("id"));
  ob1->set("player",me->query("id"));
  ob1->move(ob);
  ob->move(quest["place"]);
  
  return 1;
}

int accept_object(object who, object ob)
{
  mapping quest ;
  int exp,pots,max_pots;
  quest = who->query("quest");

  exp = (int)who->query("combat_exp");
  pots = (int)who->query("potential")-(int)who->query("learned_points");
  max_pots = (int)who->query("max_pot");
  
  if (!(ob->query("name") == "����") || !(quest["quest_type"] == "����"))
    return notify_fail("�Է�������������������\n");
  
//  if((int)time() > who->query("task_time"))
//    return notify_fail("��û�а�ʱ����ɣ������н����ˡ�\n"); 
  
  if((ob->query("player") != who->query("id")) || !who->query_temp("questduo") )
    {
      message_vision("ɽ�����˶�$N��ŭ�������ð����˵Ĺ��ͣ�\n",who);
      return 1;
    }

  message_vision("ɽ�����˶�$N˵����ɵĲ���\n",who);

  who->set("quest",0);
  who->set_temp("questduo",0);
  who->add("combat_exp",(int)quest["exp_bonus"]); 
  who->add("balance", exp/14);/*
  if((pots + (int)quest["pot_bonus"]) > max_pots) 
    who->add("potential",max_pots - pots);
  else
*/
    who->add("potential",(int)quest["pot_bonus"]); 
    who->add("shen",-10000);
  
  tell_object(who, HIW "�㱻�����ˣ�\n" +
              chinese_number((int)quest["exp_bonus"]) + "��ʵս����\n"+
              chinese_number((int)quest["pot_bonus"]) + "��Ǳ��\n"+
                            "һ��㸺��\n"+
                               "��ķֺ��Ѿ�������Ļ�ͷ���ˡ�\n" NOR);
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
  
  tell_object(me, HIW "ɽ�����˶���˵����\n ���ڸ����ھ���һ��������ߣ�");
  
  return 1;
}

