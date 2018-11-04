// NPC yupopo.c

#include <ansi.h>
#define QUEST_KILL __DIR__"quest"  
string ask_me();
inherit NPC;
int ask_job2();
int ask_job();
int ask_fail();

void create()
{
	set_name("������", ({ "yu popo", "yu", "popo" }));
	set("long",
	    "���ǡ����չ�������Ų�����첿������.\n"+
	    "������ͯ�Ѷ���, ��������,������˪.\n");
	set("title", "��첿����");
	set("gender", "Ů��");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("max_qi", 40000);
	set("max_jing", 30000);
	set("neili", 14500);
	set("max_neili", 14500);
	set("jiali", 400);
	set("combat_exp", 2500000);
	set("score", 100);
	set("score", 100);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("strike", 300);
        set_skill("sword",300);

        set_skill("tianyu-qijian",300);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 300);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "tianyu-qijian");
	set("inquiry", ([
                "��Ԯ" : (: ask_job() :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
                "�ֹ�Ʒ" : (: ask_job2() :),
                "work" : (: ask_job2() :),
                "��ɽ��" : (: ask_me :),
                "job3" : (: ask_me :),

	]) );
        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1000);
        set_temp("apply/damage", 800);

	create_family("���չ�",2,"����");
	setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",40);
}
void init()
{
        add_action("do_work", "shouwei");
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

        if( me->query("family/family_name") != "���չ�")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
	                      return 1;
            }
      if( (int)me->query_skill("bahuang-gong",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
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

        if (me->query("lingjiujob") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "������һ��Ů�������Χ����");
                command("say " + me->query("id") + " �����ڡ�" + quest["short"]             + "���ĸ�����\n" NOR);
                command("say " + me->query("id") + "��������ͻ��������Ҫ�������£�\n" NOR);
                me->set("lingjiujob", 1);
                me->set("quest/quest_type", "����");
                me->set("quest/quest", "СŮ��");
                me->set("task_time", time() + 300);
                me->apply_condition("menpai_busy",22);
                ob = new(__DIR__"dashi",1);
                ob->move(quest["place"]);
                ob->set("combat_exp", me->query("combat_exp"));
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("lingjiujob") == 1) {
                command("sigh");
                command("say �㱣������,����150��POT.");
                me->add("potential",-50);
                me->apply_condition("menpai_busy",10);
                me->apply_condition("lingjiu_song",0);
me->delete("lingjiujob");
                return 1;
                }
}

int do_work()
{
        object me, ob, weapon,obn;
int exp,pot;
        me=this_player();

        if( me->query("family/family_name") != "���չ�")
                return notify_fail("����²�����������!");

if (me->query("qi") <30)
                return notify_fail("����������ˡ�");
if (me->query("jing") <30)
                return notify_fail("��ľ������ˡ�");
        if (!me->query_temp("player_working"))
                return notify_fail("������ʲô��");

        if (me->query_temp("player_working")) {
                if (me->is_busy())
                        return notify_fail("����æ���ء�\n");

                tell_object(me, HIG"��������������������ɽ����һȦ��\n"NOR);

                        message_vision(HIW"ɽ��ô�,$N�����е��䣬����һ�����顣\n"NOR, me);
                        me->add("jing",-20);
                        me->add("qi", -10);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);

                if (me->query_temp("working_times")>=me->query_temp("player_working"))
                {
                        message_vision(HIW"�����Ŷ�$N˵���������������ˣ�����ȥ��Ϣһ�°ɡ�\n"NOR, me);
                        me->delete_temp("working_times");
                        me->delete_temp("player_working");
exp=random(20)+12;
pot=random(10)+10;
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
             tell_object(me,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܡ�\n"NOR);
                        me->start_busy(6);
                }
                return 1;
        }
        return 1;
}
string ask_me()
{
        object me;
        me=this_player();

        if( me->query("family/family_name") != "���չ�")
                return "����²�����������!";

        if (me->query_temp("player_working"))
                return "�㲻�Ǻ���������ɽ����";

                if (me->is_busy())
                        return "����æ���ء�";

        me->set_temp("player_working",random(20)+10);
        me->set_temp("working_times",0);
        return "����ͺ���һ����ɽ��(shouwei)�ɡ�";
}
int ask_job2()
{
        mapping quest ;
        object me,obn;
        int combatexp, timep;
        string room;
        me = this_player();
        if( me->query("family/family_name") != "���չ�")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
	                      return 1;
            }

        if (me->query_temp("ljjob2"))  
            {
                      message_vision("$N����$n˵:�Ҳ��Ǹ�������������?\n", this_object(), me);
                      return 1;
            }

        if ((int)me->query_condition("ljjob2"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����ո�Ҫ�����񣬵Ȼ�����!\n", this_object(), me);
                      return 1;
            }
if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N����$n˵:����û������,��Ȼ�������!\n", this_object(), me);
                      return 1;
            }  
        quest = QUEST_KILL->query_quest();
             tell_object(me,HIM" "+quest["quest"]+HIC"����һЩ��ƷҪ�׸�ͯ�ѣ���ȥ��(shougongpin)һ��!\n" NOR);

        me->set_temp("ljjob2", quest["quest"]);
          me->apply_condition("ljjob2",4);
          obn=new(__DIR__"ling");
          obn->set("usename",me->query("name"));
          obn->move(me);

        return 1;
}
int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;
object obj,me;
int maxpot;
me=who;

        if (me->is_busy())
        {
          tell_object(me,"����æ���أ�\n");
          return 0;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"�ȴ����ˣ���˵�ɣ���\n");
          return 0;
        }

        if( who->query("family/family_name") != "���չ�")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), who);
	                      return 0;
            }

        if(!who->query_temp("ljjob2"))
        {
             tell_object(who,"��û�н���ȥ��ʲô�°���\n");
             return 0;
        }

	if( userp(ob) ) {
        tell_object(who,"����ʲô���Ҳ���Ҫ��ȥҪ��Ʒ��\n");
        return 0;
        }

	if( ob->query("id")=="gong pin" &&
	ob->query("ljby")!=who->query("name")) {
        tell_object(who,"�ⲻ����Ҫ��Ҫ�Ĺ�Ʒ��\n");
        return 0;
        }

	if( ob->query("id")!="gong pin" ) {
        tell_object(who,"����ʲô���Ҳ���Ҫ��ȥҪ��Ʒ��\n");
        return 0;
        }


if ( random(30)==1 && me->query("combat_exp") > 1000000
&& !environment(me)->query("no_fight"))
{
tell_object(who,HIR"˭֪����˵��...\n"NOR);
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIR"��ʮ��������"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIR"ͻȻ����������һ�ˣ�\n"NOR, obj);
message_vision(HIR"$N˵����������ʮ�����ģ������������ҩ��������\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
me->start_busy(2);
return 0;
}

if (ob->query("id")=="gong pin" &&
	ob->query("ljby")==who->query("name")) 
{
             tell_object(who,HIW"�ҿ����ˡ�\n"NOR);

             exp = 80 + random(80);
             pot = 60 + random(50);
             score = 3 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"�����ò���ͯ��֪������˵ģ�\n"NOR);
             tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬\n"+ chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(score)+"�㽭��������\n"NOR);
             who->delete_temp("ljjob2");
who->start_busy(2);
       call_out("destroying", 0,ob);                              
return 1;
}
else return 0;
}
void destroying(object ob)
{   
   destruct(ob);
}
