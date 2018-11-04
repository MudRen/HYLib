//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
int ask_job2();
int ask_fail2();

mixed jobs = ({
        ({
"��������ڽ��ڸ���ɿ�����������ϵȾ����������ˣ���Ҫ�ɼ�����",
"���������ã��ֵ��������󷨣���ľ�����ˣ���ȥ�����￳Щ���ɿ�����",
"���Ǻ����츺���ڵص����������д��ó�����ȥ��������һ�𽫵ص������",
"�Һ�ˮ���ڽ��ڸ������춾ˮ�������ˮ�������ˣ���ȥ��ˮ��̶ȡЩˮ��",
"�ֵ����������������һЩ��������ȥ�����úô����ǹ",
        }),
        ({
         "С��","����","��ң","������","лѷ","��ǫ","��Ө��","�ܵ�","����",
	"˵����","ׯ�","�Ų���","����","��Ȼ","��ԫ","��Ұ��","������",
	 "����ԫ","�̳���","��ɽ��","������","�׹���","�⹭Ӱ","����ţ","ׯ�",
	 "�Ų���","����","��Ȼ","��ԫ","ׯ�","�Ų���","����","��Ȼ",
        }),
        });
#include "teamjob.c"
void greeting(object ob);
void create()
{
    seteuid(getuid());
    set_name("���޼�", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", "���̽������޼ɣ�ͳ������ʮ����ڣ��������ƣ�߳��ǧ�\n"
               +"�������񹦡�����Ǭ����Ų�ơ��������£��ǽ����в�������\n"
               +"����Ӣ�ۡ�\n");
    set("title",HIG "����"HIM"����"NOR);
    set("gender", "����");
    set("age", 20);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("per", 28);
    set("str", 86);
    set("int", 86);
    set("con", 80);
    set("dex", 80);

    set("qi", 19050);
    set("max_qi", 19050);
    set("jing", 19050);
    set("max_jing", 19050);
    set("neili", 38000);
    set("max_neili", 38000);
    set("jiali", 120);

    set("combat_exp", 9900000);
    set("score", 455000);
    
    set_skill("force", 250);
    set_skill("unarmed", 250);
    set_skill("dodge", 250);
    set_skill("parry", 250);
    set_skill("hand",250);
    set_skill("sword",250);
    set_skill("blade", 250);
    set_skill("cuff", 300);
    set_skill("strike", 300);
    set_skill("qingfu-shenfa", 380);
    set_skill("hanbing-mianzhang", 380);
    set_skill("sougu", 380);
    set_skill("jiuyang-shengong", 390);
    set_skill("qiankun-danuoyi", 380);
    set_skill("qishang-quan", 380);
    set_skill("shenghuo-shengong", 380);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",380);
set("jiuyangok",1);
    map_skill("force", "jiuyang-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "jiuyang-shengong");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","jiuyang-shengong");
    map_skill("blade","jiuyang-shengong");

    create_family("����",34, "����");

    set("chat_chance",2);
    set("chat_msg",({
 "���޼ɷ�Ȼ˵�������ɷ��Թ�Ϊ��, ����ɳ��, ��Ԫ��ҵδ��, ͬ������Ŭ��!��\n",
        "���޼�̾��������ʧһ֪��, ����λ�, �������, ����, ��������?��\n",
        "���޼ɵ����ҽ��ֵ�����: ��������, ���˼�Ϊ��, ��������, ������ħ!��\n",
//        	(: random_move :)
    }));

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: perform_action, "sword.lian" :),                
                (: perform_action, "sword.can" :),                
                (: perform_action, "sword.hua" :),                                	                	
                (: perform_action, "unarmed.hun" :),                                	                	
                (: perform_action, "unarmed.jiu" :),                                	                	
                (: perform_action, "unarmed.ri" :),                                	                	
                (: perform_action, "unarmed.pi" :),                                	                	                	                	                	
                (: perform_action, "unarmed.po" :),                                	                	                	                	                	
                (: command("unwield ling") :),
                (: command("exert shield") :),
                (: command("wield ling") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
    set("inquiry",([
	  "����" :     "�������ڱ�д֮�У�����Ժ�\n",
          "��ëʨ��" : "�������常л������ְ˾��\n",
          "лѷ" :     "���������常�Ĵ�š�\n",
          "�Ŵ�ɽ" :   "�������Ҹ���������? \n",
          "������" :   "����������������΢������\n",
          "������" :   "��̫ʦ�������ɺ�? \n",
          "����" :     "����ʧһ֪��, ����λ�, �������, ����, ��������?\n",
          "С��" :     "С���ҿ�һֱ�������ĺô���\n",
          "������" :   "������ȥ����ɽ, �������ҡ�\n",
		 "job"  : (: ask_jianxi :),
                "����" : (: ask_job2() :),
                "mjjob" : (: ask_job2() :),
                "��������" : (: ask_fail2() :),
                "fail" : (: ask_fail2() :),


    ]));
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
    setup();
    carry_object("/d/mingjiao/obj/yitianjian");
    carry_object("/clone/book/shenghuo-ling")->wield();
//    	carry_object("/d/mingjiao/obj/jiaozhumingpao")->wear();
    add_money("silver",70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
//      command("say
	command("wield yitian jian");
	command("hit"+(string)ob->query("id"));
        command("unwield yitian jian");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say ħ����������ѧ������������Ȱ���������������سɷ�.");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say ��λ���ѣ����н��������е����������߽�аħ���.");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say �������������ߣ�Ȱ����ӱ���.");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say �������ϣ����޼�һ�񣬴������ձ�Ϊ�����̳�.");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say �������̫���ˣ����ʺ�ѧϰ�ҵĹ���");
		return 0;
	}
	if((string)ob->query("gender")=="����")
	{
		command("say ���������㣬ϰ�ҹ���ֽ��߻���ħ��");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say ��Ӧ������Щ����������£��������ġ�");
		return 0;
	}
	command("say �ã��Ҿ���������λ��ͽ�ܣ�");
	command("say ���ְ˾���Ǳ��̵Ĺ���ʹ�ߡ�");
	command("recruit " + ob->query("id"));
	ob->set("title", HIR"����ʹ��"NOR);
	return;
}

int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("�������������ǿ���ݣ��㲻���ҵĶ��֣���ȥ�ɡ�\n",ob);
        return 0;
    }
    message_vision("���޼�һ����˵������λ"+RANK_D->query_respect(ob)+
	"����������ˡ�\n", ob);
    return 1;
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭ�ң�");
       return 0;
       }
   if(obj->query("id") == "ling qi" && me->query("mjjob") == 1
   && obj->query_temp("host")==me->query("id"))
   {
       command("nod "+(string)me->query("id"));
       command("say �ɵúã�\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }
    if(me->query("mjjob") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say �������������û����ɰ���");
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ��ҪǮ��ʲô?");
       return 0;
       }
   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 15;
   if (kar > 450) kar = 450;
   exp = 500 + kar;
   pot = 400 + kar;

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������ֹ����.\n"NOR,ob, me);
                  message_vision(HIC "\n����$N�ɹ���������������ɵ�������������\n"
                + chinese_number(exp) + "��ʵս���飬\n"
                + chinese_number(pot) + "��Ǳ�ܣ�\n"
                + chinese_number(50) + "��������Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",50);
                ckiller=3;
destruct(present("ling qi",ob));
   	        me->apply_condition("mingjiaojob",0);
//
//                me->delete("quest");
                me->delete("mjjob");
   return;      
}

int ask_job2()
{

        object me = this_player();
        object ob;
string skl,tar;

        skl = me->query_skills();

        if( me->query("family/family_name") != "����")
           {
                      message_vision("$N����$n˵���������¿������ͱ��˴��У�\n", this_object(), me);
                      return 1;
            }

        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }

if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N����$n˵:����û������,��Ȼ�������!\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("mj2_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵�����Ҫ������,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }

        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ���Ǳ��̫����!!");
                return 1;
        }

        if (me->query_temp("mj2job")) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {

tar = jobs[1][random(sizeof(jobs[1]))];
skl = jobs[0][random(sizeof(jobs[0]))];        
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "  �ҽ�Ŀ�����뷴��Ԫ����������������  �");
                command("say " + me->query("id") + " ��" + skl  + "����" NOR);
                command("say " + me->query("id") + "  �ҽ̡�" + tar  + "������������£���ȥЭ��(xiezhu)���ɣ�" NOR);
        me->delete_temp("mjjob2");
                me->set_temp("mj2job", tar);
                ob = new(__DIR__"ling");
                ob->set("usename",me->query("name"));
                ob->move(me);
                command("say " + me->query("id") + "  ��������죬���úã�ƾ���ȥ���ɣ�" NOR);
                return 1;
               }                              
}

int ask_fail2()
{
        object me = this_player();
        
        if (me->query_temp("mj2job")) {
                command("sigh");
                command("say ��ô���£��㶼�����ã�Ҳ�գ���ȥ��.");
                me->apply_condition("mj2_busy", 5 +
                        (int)me->query_condition("mj2_busy"));

me->delete_temp("mj2job");
me->delete_temp("mj2skl");
me->delete_temp("mj2jobs");
                return 1;
                }
}
