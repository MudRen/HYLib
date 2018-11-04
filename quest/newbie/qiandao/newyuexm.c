// yue.c ��Сõ
// lag 2000.5.9
#include <ansi.h>
inherit NPC;

int ask_job();
int ask_fail();


void create()
{
        set_name("��Сõ", ({ "yue xiaomei", "yue" }));
        set("nickname", HIC "���´���С��ٻ" NOR);
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 55);
        
        set("qi", 20000);
        set("max_qi", 20000);
        set("jing", 20000);
        set("max_jing", 20000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 250);
	set("combat_exp", 6000000);
	set("score", 500000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set_skill("force", 400);
	set_skill("taiji-shengong", 400);
	set_skill("dodge", 400);
	set_skill("tiyunzong", 400);
	set_skill("unarmed", 400);
	set_skill("taiji-quan", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("taiji-jian", 400);
	set_skill("liangyi-jian", 400);
	set_skill("wudang-array", 400);
	set_skill("array",400);
	set_skill("taoism", 400);
	set_skill("literate", 400);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

        set("inquiry", ([
                "����" : (: ask_job() :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
                "fail" : (: ask_fail() :),
          ])),

        set("env/important", 1);    
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 500);

        setup();
	carry_object("/clone/weapon/changjian")->wield();
          carry_object("/d/city/obj/cloth")->wear();
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


   if(this_object()->is_busy())
{
message_vision("��Сõ��$N˵����������æ���أ���\n",me);
return 1;
}
   if(this_object()->is_fighting())
{
message_vision("��Сõ��$N˵����������æ���أ���\n",me);
return 1;
}

//   if(me->query("potential") > 200000)
//{
//message_vision("��Сõ��$N˵���������Ǳ��̫���ˣ��Ҳ��ܸ������񣡡�\n",me);
//return 1;
//}
           if (me->query("combat_exp") < 80000) {
                command("say " + RANK_D->query_respect(me) + "ɱǿ���ɲ���һ�����׵����飬�㻹�����߾���������");
                return 1;
}
        if (me->query("potential") < 200 || me->query("combat_exp") < 30000) {
                command("say ������Ǯ��û�У�����ô����Ҫ��ȥɱǿ���أ�");
                return 1;
        }
        if (me->query("kill_qiangdao") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "��Ϊ������Ե����������̫���ˡ�");
                command("say " + me->query("id") + " ǿ���ڡ�" + quest["short"]             + "������ȥ�ɣ�\n" NOR);
                me->set("kill_qiangdao", 1);
                me->set("quest/quest_type", "ɱ");
                me->set("quest/quest", "ǿ��");
                me->set("task_time", time() + 310);
                this_object()->start_busy(1);
                ob = new(__DIR__"qiangdao",1);
                if (me->query("combat_exp") > 2000000) {
                ob = new(__DIR__"qiangdao2",1);
                }
                ob->move(quest["place"]);
                me->start_busy(3);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp")+random(100000));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                ob->set("neili",me->query("max_neili")*2 );
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_fail()
{
string mapa;
        object me = this_player();
        
        if (me->query("kill_qiangdao") == 1) {
                command("haha");
                command("say ��������Ҳ�����ͼ���񣬶���Сõ�ҵ�����������,����80��POT.");
//              command("chat " + me->query("name") + "û���湦����ʹǿ��Σ��һ�������ڷ���" + me->query("name") + "ȥ�߽���");
 //               command("rumor* sigh");
if (random(3)==0)
{
mapa="/d/xingxiu/tianroad";
                me->move(mapa+(random(6)+1));
}
else if (random(3)==1)
{
mapa="/d/xingxiu/xxh";
               me->move(mapa+(random(6)+1));
}
else if (random(3)==2)
{
mapa="/d/xingxiu/silk";
               me->move(mapa+(random(4)+1));
}

else
{
mapa="/d/xingxiu/xxroad";
           me->move(mapa+(random(6)+1));
}
if (me->query("potential") >100)
{
                me->add("potential",-80);
}
me->delete("kill_qiangdao");
                return 1;
                }
}

