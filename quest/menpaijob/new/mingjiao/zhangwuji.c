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
    set("str", 36);
    set("int", 36);
    set("con", 30);
    set("dex", 30);

    set("qi", 4050);
    set("max_qi", 4050);
    set("jing", 4050);
    set("max_jing", 4050);
    set("neili", 18000);
    set("max_neili", 18000);
    set("jiali", 120);

    set("combat_exp", 9900000);
    set("score", 455000);
    
    set_skill("force", 250);
    set_skill("unarmed", 200);
    set_skill("dodge", 200);
    set_skill("parry", 220);
    set_skill("hand",200);
    set_skill("sword",250);
    set_skill("blade", 200);
    set_skill("cuff", 250);
    set_skill("jiuyang-shengong", 300);
    set_skill("qiankun-danuoyi", 300);
    set_skill("qishang-quan", 300);
    set_skill("shenghuo-shengong", 300);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",300);

    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","shenghuo-ling");
    map_skill("blade","taiji-dao");

    create_family("����",34, "����");

    set("chat_chance",2);
    set("chat_msg",({
 "���޼ɷ�Ȼ˵�������ɷ��Թ�Ϊ��, ����ɳ��, ��Ԫ��ҵδ��, ͬ������Ŭ��!��\n",
        "���޼�̾��������ʧһ֪��, ����λ�, �������, ����, ��������?��\n",
        "���޼ɵ����ҽ��ֵ�����: ��������, ���˼�Ϊ��, ��������, ������ħ!��\n",
//        	(: random_move :)
    }));

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: command("unwield ling") :),
                (: command("unwield ling") :),
                (: command("wield ling") :),
                (: command("wield ling") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
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
   if(obj->query("id") == "ling qi" && me->query("mjjob") == 1)
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
   exp = 1200 + kar;
   pot = 600 + random(exp);

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������ֹ����.\n"NOR,ob, me);
                  message_vision(HIC "\n����$N�ɹ���������������ɵ�������������\n"
                + chinese_number(exp / 2) + "��ʵս���飬\n"
                + chinese_number(pot / 2) + "��Ǳ�ܣ�\n"
                + chinese_number(50) + "��������Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp / 2);
                me->add("potential", pot / 2);
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
