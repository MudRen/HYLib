// hehongyao.c
// �κ�ҩ
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();

string ask_jianxi();
string ask_finish();
mixed names = ({
        ({
        "�嶫��","�һ�������","����С·","�һ���","�嶾ɽ·",
        "С���","�򶾿���","�򶾿�","·��С��","ɽ��С·",
        "�������","��ɭ��","��ɽС·","��Ѩ","��Ѩ�",                
        "������","����","��������","����ͤ","�ܷ�ͤ", 
        "������","�ٶ�����","������","�ٶ���","ǧ����",
        "ǧ������","�ٶ���","�嶾�̴���","�ٲ�","�ݵ�",
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
        set_name("�κ�ҩ", ({ "he hongyao", "he" }));
        set("nickname", HIG "����ؤ��" NOR);
        set("long",@LONG
�������嶾�̵ĳ��ϣ������Ĺùúκ�ҩ����Ȼ�ǽ����ĳ�����������ȴ��һ���
�ϴ�����ѧ�ġ���˵����������Ϊ�����̳��ˣ����������´�����Ա������˴�
����ʥ�أ�����ǰ�������һ���ƾɵ������������̺ۣ����ù������˫Ŀ��
����Թ��֮ɫ��
LONG
        );
        set("title","�嶾�̳���");
        set("gender", "Ů��");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 19000);
        set("max_jing", 19000);
        set("neili", 14000);
        set("max_neili", 14000);
        set("jiali", 100);
        set("combat_exp", 6500000);
        set("score", 500000);
        set("inquiry", ([
   	    "����"  : (: ask_jianxi :),
	    "job"  : (: ask_jianxi :),
   	    "���"  : (: ask_finish :),
	    "finish"  : (: ask_finish :),
   	    "ӭ��"  : (: ask_job :),
	    "attackjob"  : (: ask_job :),
            "attackfail" : (: ask_fail() :),
            "ӭ��ʧ��" : (: ask_fail() :),
        ]));

        set_skill("force", 280);
        set_skill("wudu-shengong", 320);
        set_skill("dodge", 190);
        set_skill("wudu-yanluobu", 280);
        set_skill("unarmed", 160);
        set_skill("qianzhu-wandushou", 280);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("wudu-goufa", 380);
        set_skill("poison", 260);
        set_skill("literate", 80); 
        set_skill("finger",160);
        set_skill("shedu-qiqiao",360);
//      set_skill("hammer", 100);
//      set_skill("jinshe-chui", 150 );
//      set_skill("huoyan-dao", 200);
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
         set("chat_chance_combat", 90);
         set("chat_msg_combat", ({
                (: perform_action, "finger.sandu" :),
                (: perform_action, "sword.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "finger.sandu" :),
                (: perform_action, "dodge.snake" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),		
        }) );


        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//      map_skill("hammer", "jinshe-chui");
//      map_skill("strike","huoyan-dao");

        create_family("�嶾��", 11, "����");
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        setup();

        carry_object("d/wudujiao/npc/obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("d/wudujiao/npc/obj/wuxing");

        add_money("gold",10);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "����") {
                                 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
                  }

                  if ((int)ob->query("shen") > -10000) {
                                 command("say �����嶾�̵��ӱ����ĺ�������");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ĵ�������ϧ���ҽ�û��Ե�ְ���");
                return;
                  }

        if ((string)ob->query("family/family_name") != "�嶾��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���Ǳ��̵��ӣ�������ذɣ�");
                return;
                  }

        if ((int)ob->query_skill("poison", 1) < 100) {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 100) {
                command("say ����嶾�񹦻�ѧ�Ĳ�������");
                return;
        }

          command("chat �ٺٺٺ٣���������");
          command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");
          command("chat �ٺٺٺ٣���������");
          command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title","�嶾�̻���");
       return;
}

string ask_jianxi()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "�嶾��")
           {
                      message_vision("$N����$n���һ�������̵��Ӳ������������������ģ�\n", this_object(), ob);
                      return  "���ߡ�";
            }

    if ((int)ob->query_skill("wudu-shengong",1) < 30 ) {
                      message_vision("$N����$n���һ������ı����ڹ�̫���ˣ�\n", this_object(), ob);
                      return  "���ߡ�";
    } 

	  if(ob->query("combat_exp")<10000)
      return  "��Ĺ���̫���ˡ�";
      if(ob->query_temp("wudujiao"))
      return  "�㲻�����ڸɻ!";
if ((int)ob->query_condition("guojob2_busy"))
        return  "��սӹ����񣬵Ȼ�������";
     if(ob->query_condition("wdj_busy"))
        return  "��սӹ����񣬵Ȼ�������";


     if(ob->query_condition("wdj_busy"))
        return  "��սӹ����񣬵Ȼ�������";
      
	  where=names[0][random(30)];
	  ob->set_temp("wudujiao",1);
	  ob->set_temp("wudujiaojob",where);
          ob->apply_condition("wdj_busy",8);
if (!ob->query_skill("wudu-shengong",1))
{
ob->apply_condition("wdj_busy",12);
}

          obn=new(__DIR__"saozhou");
          obn->move(ob);
	  return    HIW"�Ҹյõ����������Ҫ��������찵����\n"+
           "          ��Ͽ�ȥ"+where+"׽һЩ����(zuoduwu)��\n"+
           "          ���������ɵ��������ˣ������˾͸���ɱ�ˡ�"NOR; 
}

string ask_finish()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
      if(!ob->query_temp("wudujiao"))
      return  "��û����ɹ��!";

	  if(!ob->query_temp("wudujiaook"))
      return  "��Ļ�û���갡!";
        ob->delete_temp("wudujiao");
        ob->delete_temp("wudujiaojob");
        ob->delete_temp("wudujiaook");
        ob->add("combat_exp",50+random(150));
        ob->add("potential",25+random(100));
	  return    HIY"���úã���\n"+
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
	  
        if( ob->query("family/family_name") != "�嶾��")
           {
                      message_vision("$N����$n����һЦ�����̵��Ӳ������������������ģ�\n", this_object(), ob);
                      return  "���ߡ�";
            }
    if ((int)ob->query_skill("wudu-shengong",1) < 30 ) {
                      message_vision("$N����$n���һ������ı����ڹ�̫���ˣ�\n", this_object(), ob);
                      return  "���ߡ�";
    } 
if ((int)ob->query_condition("guojob2_busy"))
        return  "��սӹ����񣬵Ȼ�������";
     if(ob->query_condition("wdj2_busy"))
        return  "��սӹ����񣬵Ȼ�������";

     if(ob->query("combat_exp")<100000)
      return  "��Ĺ���̫���ˡ�";
        if (ob->query_temp("wdhw")) {
                command("kick " + ob->query("id"));
      return  "�Ҳ��Ǹ�������������";
                }
        if (ob->query_temp("wdhwjob")) {
                command("kick " + ob->query("id"));
      return  "�Ҳ��Ǹ�������������";
                }
      
	  where=names[0][random(30)];
	  ob->set_temp("wdhw",1);
	  ob->set_temp("wdhwjob",where);
          ob->apply_condition("wdj2_busy",22);
if (!ob->query_skill("wudu-shengong",1))
{
ob->apply_condition("wdj2_busy",25);
}

          obn=new(__DIR__"ling");
          obn->set("usename",ob->query("name"));
          obn->move(ob);
	  return    RED"�Ҹյõ���Ϣ���������ɣ��мƻ�Ҫ��͵Ϯ���̡�\n"+
           "          ��Ͽ�ȥ"+where+"ӭ��һ�°�(yingji)��\n"+
           "          ������������͵Ϯ���������ǡ�"NOR; 
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query_temp("wdhwjob")) {
                command("sigh");
                command("say ��ô���£��㶼�����ã�Ҳ�գ���ȥ��.");
          me->apply_condition("wdj2_busy",30);
destruct(present("wd lingqi",me));
       me->delete_temp("wdjob");
        me->delete_temp("wdhw");
        me->delete_temp("wdhwjob");
        return 1;
                }
}

