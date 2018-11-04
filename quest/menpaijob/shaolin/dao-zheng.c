// Npc: /kungfu/class/shaolin/dao-zheng.c
// Date: YZC 96/01/19
#include <ansi.h>
inherit NPC;
int ask_job2();
int ask_job();
int ask_fail();
int ask_fail2();
mixed names = ({
        ({
        "���ֵ���","Τ����","��������","Ħڭָ","����צ",
        "��������","����Ҷָ","������","Τ�Թ�","��Ħ��",
       "���","�޳���","�ն���","���޵�","�ȱ���",                
        "����ȭ","�黨ָ","һָ��","ӥצ��","��צ��", 
        "������","����ǧҶ��","������","ɢ����","�޺�ȭ",
        }),
        ({
         "��־","�ι�","�κ�","�μ�","�μ�","�ξ�","����","����","����",
	"����","��ʶ","��˼","����","����","����","����","����",
	 "��֪","��һ��ʦ","������ʦ","������ʦ","��Ʒ��ʦ","������ʦ","������ʦ","������ʦ",
	 "������ʦ","�ۺ�����","��������","�۽�����","�ۿ�����","��������","��������","��ɫ����",
	 "��������","��������","�巨����","�μ�","��۱���","���ֱ���","���Ʊ���","��Ϊ����",
	 "���ű���","���ޱ���","��������","������ʦ","����","����","������ʦ",
        }),
        });
void create()
{
	set_name("������ʦ", ({
		"daozheng chanshi",
		"daozheng",
		"chanshi",
	}));
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 40000);
	set("max_jing", 30000);
	set("neili", 14500);
	set("max_neili", 14500);
	set("jiali", 400);
	set("combat_exp", 8000000);
	set("score", 100);

	set_skill("force", 350);
	set_skill("hunyuan-yiqi", 350);
	set_skill("dodge", 350);
	set_skill("shaolin-shenfa", 350);
	set_skill("strike", 350);
	set_skill("sanhua-zhang", 350);
	set_skill("parry", 350);
	set_skill("damo-jian", 350);
	set_skill("buddhism", 350);
	set_skill("literate", 350);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "sanhua-zhang");
	map_skill("parry", "sanhua-zhang");
	set("inquiry", ([
                "��ɮ��" : (: ask_job2() :),
                "wsjob" : (: ask_job2() :),
                "��Ԯ" : (: ask_job() :),
                "job" : (: ask_job() :),
                "fail" : (: ask_fail() :),
                "ʧ��" : (: ask_fail() :),
                "������ɮ��" : (: ask_fail2() :),
                "wsfail" : (: ask_fail2() :),
	]) );
	create_family("������", 39, "����");

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

int ask_job()
{

        object me = this_player();
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

        if( me->query("family/family_name") != "������" && me->query("family/family_name") != "��������")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
      if( (int)me->query_skill("yijinjing",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�㻹�����߾���������");
                return 1;
}
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ���Ǳ��̫����!!");
                return 1;
        }

        if (me->query("shaolinjob") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "�������Ѵ�ʦ���Χ����");
                command("say " + me->query("id") + " ���Ѵ�ʦ���ڡ�" + quest["short"]             + "���ĸ�����\n" NOR);
                command("say " + me->query("id") + "������Ѵ�ʦ��ʦ���ͻ����֣�\n" NOR);
                me->set("shaolinjob", 1);
                me->apply_condition("menpai_busy",22);
                me->set("quest/quest_type", "����");
                me->set("quest/quest", "���Ѵ�ʦ");
                me->set("task_time", time() + 300);
                ob = new(__DIR__"dashi",1);
                ob->move(quest["place"]);
                ob->set("combat_exp", me->query("combat_exp"));
                return 1;
               }                              
}

int ask_job2()
{

        object me = this_player();
        object ob;
string skl,tar;

        skl = me->query_skills();

        if( me->query("family/family_name") != "������"  && me->query("family/family_name") != "��������")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }

        if ((int)me->query_condition("slwsd_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵�����Ҫ������,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N����$n˵:����û������,��Ȼ�������!\n", this_object(), me);
                      return 1;
            }  
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ���Ǳ��̫����!!");
                return 1;
        }
      if( (int)me->query_skill("yijinjing",1) < 10)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
        if (me->query_temp("wsdjob")) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {

tar = names[1][random(sizeof(names[1]))];
skl = names[0][random(sizeof(names[0]))];        
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "�����书���࣬��Ҫ��ɮ�������С�");
                command("say " + me->query("id") + " ��ȥ�͡�" + tar  + "��һ������һ�¡�" + skl  + "���ɣ�\n" NOR);
                me->set_temp("wsdjob", tar);
                me->set_temp("wsdskl", skl);
                ob = new(__DIR__"ling");
                ob->set("usename",me->query("name"));
                ob->move(me);
                command("say " + me->query("id") + "�����ɮ����úã�ƾ���ȥ�������������аɣ�\n" NOR);
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("shaolinjob") == 1) {
                command("sigh");
                command("say �㱣������,����150��POT.");
                me->add("potential",-50);
                me->apply_condition("shaolin_song",0);
                me->apply_condition("menpai_busy",10);
me->delete("shaolinjob");
                return 1;
                }
}

int ask_fail2()
{
        object me = this_player();
        
        if (me->query_temp("wsdjob")) {
                command("sigh");
                command("say ��ô���£��㶼�����ã�Ҳ�գ���ȥ��.");
                me->apply_condition("slwsd_busy", 5 +
                        (int)me->query_condition("slwsd_busy"));

//                me->apply_condition("slwsd_busy",6);
me->delete_temp("wsdjob");
me->delete_temp("wsdskl");
me->delete_temp("wsjob");
                return 1;
                }
}

