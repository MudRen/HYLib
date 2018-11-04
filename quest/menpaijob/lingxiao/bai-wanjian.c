//LUCAS 2000-6-18
#include <ansi.h>
inherit NPC;

inherit F_MASTER;
int ask_fail();
string  ask_job();

string ask_jianxi();
string ask_finish();
mixed names = ({
        ({
        "ɽ��","����","������","ѩɽ��Ȫ","��紨",
        "ɽ·","��������","��ѩ��","����","��ͷ",
        "����","������","������","����","�ƺ�ʯ",                
        "Ϸ÷ͤ","����","����С��","��ͥ","�ɻ���", 
        "��԰","����","������","����","С��",
        "���¾�","����","ľ��","ʯ�¿�ջ","÷��",
        }),
        ({
         "�α�","ƫ��","�Խ�","����","С��","�к�","��ܽ","������",
		 "С��","����ϰ�","����ͨ","�","����","������","��С��","�α�",
		 "����ʦ̫","����ʦ̫","��Զ��","Ī����","½�˷�","������","��ҩʦ","��׺�",
		 "��Ұ��","����ţ","��־ƽ","С��Ů","���з�","ŷ����","������Ů","�������",
		 "����","������","������","������","����Ⱥ","�����","�����ʦ","���Ʊ���",
		 "��������","ׯ����","˫��","������","ľ����","��Զɽ","������","������",
		 "����","�ڰ���","������","������","�彣��","��ص���","����","����",
		 "��ɽͯ��","ΤһЦ","лѷ","�μ�","½�˷�","�Ŵ�ɽ","������","�������",
		 "ʯ����","���Ǻ�","��ң��","�쵤��","����","�ⲻƽ",
        }),
        });

void create()
{
        set_name("����",({"bai wanjian","bai"}));
        set("nickname", HIC"��������"NOR);
        set("gender", "����");
        set("age", 30);
        set("long", 
               "������ѩɽ���������������������ڵĳ��ӣ���\n"
                "��ʦ�ֵܾ��ԡ��������У������־�Ȼ�е�����,\n"
                "�������֮��.�������������,�롮�������������\n"
                "��ϳơ�ѩɽ˫�ܡ���\n");
        set("attitude", "peaceful");

        set("str", 50);
        set("con", 50);
        set("int", 50);
        set("dex", 50);
        set("per", 50);
        set("neili", 33000);
        set("max_neili", 33000);
        set("jing", 18000);
        set("max_jing", 18000);
        set("qi", 18000);
        set("max_qi", 18000);
        set("jiali", 100);

        set("combat_exp", 7500000);
        set("score", 50000);
        set("inquiry", ([
            "������"   : "��ү�ӵ�̨�����е���!��",
            "��ү��"   : "����ݼ���ү���𣿵����չ����,����ҳ�ʦ��Ҫ������,���ܼ�������",
            "����"   : 
     "����ݼ���ү���𣿵����չ����,����ҳ�ʦ��Ҫ������,���ܼ�������",
            "����"   : "���������������ر�,ֻ��ƾ��,���ܽ��������",
   	    "����"  : (: ask_jianxi :),
	    "job"  : (: ask_jianxi :),
   	    "����"  : (: ask_job :),
	    "huweijob"  : (: ask_job :),
            "huweifail" : (: ask_fail() :),
            "����ʧ��" : (: ask_fail() :),
   	    "���"  : (: ask_finish :),
	    "finish"  : (: ask_finish :),

        ]));
        set("shen_type", 1);


        set_skill("unarmed", 280);
        set_skill("sword", 280);
        set_skill("force", 230);
        set_skill("parry", 230);
        set_skill("dodge", 230);
        set_skill("literate", 180);

        set_skill("xueshan-sword", 320);
        set_skill("bingxue-xinfa", 320);
        set_skill("snow-zhang", 300);
        set_skill("snowstep", 300);
        set_skill("doom-hand", 300);
        set_skill("hanshan-strike", 300);
        set_skill("snowwhip", 300);
        set_skill("hand", 250);
        set_skill("whip", 250);
         set_skill("strike", 280);
        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "dodge.snowfly" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: perform_action, "strike.zhangjian" :),
                (: perform_action, "strike.siji" :),
	               (: perform_action, "hand.hantian" :),                		
                (: exert_function, "powerup" :),
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("������", 6, "����");
        setup();

        
        carry_object("/clone/money/gold.c");
        carry_object("/d/lingxiao/obj/baihongjian.c")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 28) {
        command("say ����������,���ܸ���ѧ����");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 60 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
                return;
    } 
    if ((int)ob->query_skill("xueshan-sword",1) < 80 ) { 
        command("say ��ı��Ž���̫����,����������ԭ����ʦ����߰�!"); 
                return;
        }
    if ((int)ob->query_skill("sword",1) < 80 ) {  
        command("say ��Ļ�������̫����,��������߻�������!"); 
                return; 
    }
    if ((int)ob->query("shen") < 20000 ) {
         command("say ѧ��������������������?"); 
                return;
    } 

    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", "�����ǵ��ߴ�����"); 
}

string ask_jianxi()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "������")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ģ�\n", this_object(), ob);
                      return  "���ߡ�";
            }

    if ((int)ob->query_skill("bingxue-xinfa",1) < 30 ) {
                      message_vision("$N����$n���һ������ı����ڹ�̫���ˣ�\n", this_object(), ob);
                      return  "���ߡ�";
    } 


if ((int)ob->query_condition("guojob2_busy"))
        return  "��սӹ����񣬵Ȼ�������";
     if(ob->query_condition("lingxiao_busy"))
        return  "��սӹ����񣬵Ȼ�������";

	  if(ob->query("combat_exp")<10000)
      return  "��Ĺ���̫���ˡ�";
            if(ob->query_temp("lingxiao"))
      return  "�㲻�����ڸɻ!";

	  where=names[0][random(30)];
	  ob->set_temp("lingxiao",1);
	  ob->set_temp("lingxiaojob",where);
          ob->apply_condition("lingxiao_busy",8);
if (!ob->query_skill("bingxue-xinfa",1))
{
ob->apply_condition("lingxiao_busy",9);
}
          obn=new(__DIR__"saozhou");
          obn->move(ob);
	  return    WHT"�Ҹյõ���Ϣ������ѩ�µ�̫�󣬰�·�����ˡ�\n"+
           "          ��Ͽ�ȥ"+where+"ɨһ��ѩ��(saoxue)��\n"+
           "          �����б�����ɵ��������ˣ����С�ġ�"NOR; 
}

string ask_finish()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
      if(!ob->query_temp("lingxiao"))
      return  "��û����ɹ��!";

	  if(!ob->query_temp("lingxiaook"))
      return  "��Ļ�û���갡!";
        ob->delete_temp("lingxiao");
        ob->delete_temp("lingxiaojob");
        ob->delete_temp("lingxiaook");
        ob->add("combat_exp",50+random(150));
        ob->add("potential",25+random(100));
	  return    HIW"���úã���\n"+
           "          ��ָ������ֹ���ɡ�\n"+
           "          ��ľ����Ǳ��������!"NOR; 
}


string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "������")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ģ�\n", this_object(), ob);
                      return  "���ߡ�";
            }

    if ((int)ob->query_skill("bingxue-xinfa",1) < 30 ) {
                      message_vision("$N����$n���һ������ı����ڹ�̫���ˣ�\n", this_object(), ob);
                      return  "���ߡ�";
    } 

if ((int)ob->query_condition("guojob2_busy"))
        return  "��սӹ����񣬵Ȼ�������";
     if(ob->query_condition("lingxiao2_busy"))
        return  "��սӹ����񣬵Ȼ�������";


     if(ob->query("combat_exp")<100000)
      return  "��Ĺ���̫���ˡ�";
        if (ob->query_temp("lxhw")) {
                command("kick " + ob->query("id"));
      return  "�Ҳ��Ǹ�������������";
                }
        if (ob->query_temp("lxhwjob")) {
                command("kick " + ob->query("id"));
      return  "�Ҳ��Ǹ�������������";
                }
      
	  where=names[0][random(30)];
	  ob->set_temp("lxhw",1);
	  ob->set_temp("lxhwjob",where);
          ob->apply_condition("lingxiao2_busy",22);
if (!ob->query_skill("bingxue-xinfa",1))
{
ob->apply_condition("lingxiao2_busy",25);
}
          obn=new(__DIR__"ling");
          obn->set("usename",ob->query("name"));
          obn->move(ob);
	  return    RED"�Ҹյõ���Ϣ����ν���������ɣ����˼�������ս���ɡ�\n"+
           "          ��Ͽ�ȥ"+where+"����һ�°�(huwei)��\n"+
           "          ��������������ս���������ǡ�"NOR; 
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query_temp("lxhwjob")) {
                command("sigh");
                command("say ��ô���£��㶼�����ã�Ҳ�գ���ȥ��.");
          me->apply_condition("lingxiao2_busy",32);
       destruct(present("lx lingpai",me));
       me->delete_temp("lxjob");
        me->delete_temp("lxhw");
        me->delete_temp("lxhwjob");
        return 1;
                }
}

