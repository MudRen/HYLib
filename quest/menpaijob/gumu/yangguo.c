// yangguo.c ���
// By Kayin @ CuteRabbit Studio 99-4-16 21:10 new
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
void create()
{
	set_name("���", ({ "yang guo", "yang" }));
	set("nickname", HIG "������" NOR);
	set("gender", "����");
	set("age", 25);
	set("per",80);
	set("con",80);
	set("str", 80);
	set("class","gumu");
	set("dex", 80);
	set("long", "����һλ�ߴ�����ӣ���ò���㡣\n"+
	"һֻ����տ���Ҳ�����Ƕ���һ�ۣ�������ˣ�\n"+
	"��Ȼ�ڲ�ס�����˵ķ�ɡ�����Ը����д�(qiecuo)\n");
	set("combat_exp", 10000000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("sword", 350);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("yunv-xinfa", 320);
	set_skill("anranxiaohun-zhang",380);
	set_skill("xuantie-sword", 390);
	set_skill("xiantian-qigong", 200);
	set_skill("yunv-shenfa",300);
        set_skill("yunv-jian", 320);  
        set_skill("tianluo-diwang", 320); 
                set_skill("meinv-quan", 320); 
                        set_skill("wuzhan-mei", 320); 
                                set_skill("yinsuo-jinling", 320);         




	map_skill("sword", "xuantie-sword");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "yunv-shenfa");
	map_skill("force", "yunv-xinfa");

	set("chat_chance_combat", 99);
       set("chat_msg_combat", ({
                (: perform_action, "parry.anran" :),
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "parry.jingtao" :),
                (: perform_action, "parry.sad" :),
                          (: perform_action, "tuo" :),


                (: exert_function, "recover" :),
                (: perform_action, "sword.feihongrudian" :),
                 (: perform_action, "sword.botao" :),
                (: perform_action, "sword.lei" :),
                (: perform_action, "sword.juan" :),
                (: perform_action, "sword.dong" :),
                (: perform_action, "sword.dang" :),
                (: perform_action, "sword.hai" :),					
                (: perform_action, "sword.qianjun" :),		            
        }) );

if (random(2)==0) 
	{
	map_skill("sword", "yunv-jian");

	set("chat_chance_combat", 99);
       set("chat_msg_combat", ({
                (: perform_action, "sword.hebi long" :),
            		(: command("perform sword.hebi long") :),
                (: perform_action, "parry.anran" :),
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "parry.jingtao" :),
                (: perform_action, "parry.sad" :),
                          (: perform_action, "tuo" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
        }) );
   }     
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
	set("neili", 55000); 
	set("max_neili", 55000);
	set("max_qi", 25000);
	set("qi",25000);
	set("max_jing", 25000);
	set("jing",25000);
        set("inquiry", ([
                "С��Ů" : "������С���\n",
"��ʦ": "��������������书��Ȼ���پ����ղ����㡣��������(accept test)��\n",
"�д�":"����Ը��ҽ����д�(qiecuo)\n",
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
       ]) );
       create_family("��Ĺ��", 3, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("d/gumu/npc/obj/tiesword")->wield();
	add_money("gold", 2);
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
	add_action("do_qiecuo","qiecuo");
	add_action("do_killing", "kill");
	add_action("do_killing", "touxi");
	add_action("do_killing", "hit");
	add_action("do_killing", "ansuan");
	add_action("do_killing", "qiangjian");
}

void attempt_apprentice(object ob)
{ 
  if(!ob->query("marks/beguo"))
	  return;
else {
 command("recruit " + ob->query("id") );
ob->set("title",HIW"����մ�����"NOR);
}
 return;
}
int recognize_apprentice(object ob)
{
  if(!ob->query("marks/win_guo_time"))
	  return 0;
  if((time() - ob->query("marks/win_guo_time") ) > 900)
  {
    say("���˵�����������ѧ�˲����ˣ�������������(qiecuo)һ�°ɣ�\n");
    return 0;
  }
 return 1;
}

int do_qiecuo()
{
    mapping guild;
    int skee,dkee;
    object me,target;
	
	me=this_player();
	target=this_object();
	skee=target->query("qi");
	
	if((time()-me->query("marks/win_guo_time"))<900)
	{
     command("say ��Ĺ����治���������д�����\n");
	 return 1;
	}
	if(!me)
	{
     command("say ���أ�\n");
	 return 1;
	}
	if(!me->query_temp("weapon"))
	{
     command("say ��������أ�\n");
	 return 1;
	}

	//if who have qiecuo,and the time have beyond 2 hours,then he can qiecuo
	if(time() - me->query("marks/qiecuo_last_time")>72000)
	{
     
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
	 say("\n�������һ�У�������\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n����������У�������\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n����������У�������\n");
	 dkee=target->query("qi");
     if(!(dkee<skee)) 
	 {
      say("���˵�����������书���У���������Щ�����ɣ�\n");
	  me->set("marks/qiecuo_last_time",time());
     }
	 else
	 {
            
      say("\n���˵������Ĺ����治���ӽ��Ժ����Ǿ��໥ѧϰ�ɣ�\n");
	  me->set("marks/win_guo_time",time());
	 }
	 return 1;
	}
    say("���˵�����㲻��ǰ������ң��������ٱȰɣ�\n");
    return 1;
}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
	if((string)this_player()->query("family/family_name") != "��Ĺ��") 
		{
			command("say ����ȥ���ҹùðɡ�\n");
			return 1;
		}
	else if(this_player()->query("shen")>50000)
		{
			command("say �������������������Щ��ν����������򽻵���\n");		return 1;}
	else if(this_player()->query("shen")<-50000)
		{
			command("say �����������ʹ��������Ща���������ҹ���\n");		return 1;}
	else if((string)this_player()->query("family/family_name") != "��Ĺ��" && this_player()->query("str")<28)
		{
			command("say �����̫�ѧ�����ҵ��书��\n");
		return 1;}
	else if(this_player()->query("combat_exp")<1000000)
		{
			command("say �㵱����˭������Ҳ��ѧ���书����ľ���̫����!��\n");
		return 1;}

	else if(this_player()->query("family/master_id") == this_object()->query("id"))
	{
	say("\n����������ͷ�����㽫���ض���һ������֮���ˣ�\n");
	return 1;
	}
	
                say("\n������˵�ͷ��˵�����ܺã����������У����ǵ�һ��....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("���̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
                 this_player()->die();
	       return 1;
		}
                say("\n���˵�����������ǵڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("������ߡ���һ����˵��������������಻�����ļһ�....\n");
                this_player()->die();     
	   return 1;
                }
                say("\n���˵��������������....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("���̾������ϧ����������Ե��....\n");
                       this_player()->die();
 return 1;
                }
                
say("\n���������Ц��˵������������ٵ�һ������֮�ţ�\n\n");
                this_player()->set("marks/beguo",1);
	return 1;
        }
        return 0;
}
int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "С��Ů")
		{
		message_vision("$N��Цһ��������ɱ�ҹùã��ҿ�����̫���ˡ�\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		victim->kill_ob(player);
		return 1;
		}
	}
	return 0;		
}

int ask_job()
{

        object me = this_player();
        object guo = this_object();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = (__DIR__"lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N����$n˵:����û������,��Ȼ�������!\n", this_object(), me);
                      return 1;
            }

        if (me->query_condition("gumu_job"))
           {
                      message_vision("$N����$n˵:����û������,��Ȼ�������!\n", this_object(), me);
                      return 1;
            }
      if( (int)me->query_skill("yunv-xinfa",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }

        if( me->query("family/family_name") != "��Ĺ��")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ļ�ϸ��\n", this_object(), me);
                     return 1;
            }
           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�����������ѵģ��㻹�����߾���������");
                return 1;
}
            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ������Ǯ��û�У�����ô����Ҫ��ȥ����������");
                return 1;
        }

        if (me->query("kill_gumu") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "��Ϊ���ҳ���������̫���ˡ�");
                command("say " + me->query("id") + " һ���ɹű��ڡ�" + quest["short"]             + "�����֣���ȥ�ɣ�\n" NOR);
                me->set("kill_gumu", 1);
	        me->apply_condition("gumu_job",15);
                me->set("quest/quest_type", "ɱ");
                me->set("quest/quest", "�ɹű�");
                me->set("task_time", time() + 300);
                ob = new(__DIR__"qiangdao",1);
                }
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
//}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_gumu") == 1) {
                command("sigh");
                command("say ��������Ҳ����������!!");
                                me->delete("kill_gumu");
                me->apply_condition("gumu_job",16);
               me->delete("kill_gumu");
                return 1;
                }
}

