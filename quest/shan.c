// shan.c

inherit NPC;
//inherit F_SKILL;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
	set_name("����", ({ "shan zheng", "shan", "zheng" }));
	set("nickname", HIB"�����й�"NOR);
	set("age", 63);
	set("str", 25);
	set("dex", 16);
	set("per", 22);
	set("long", 
"����ƽ�������ֻҪ֪����������ʲô������֮�£���Ȼ����
Ҫ�ܡ���������⣬������ͯ�պ׷������֣�����ȴ��ǫ�ͣ�
���ƽ����ϴ�˵�ĳ������顣\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 50);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me,ob;
        int j, combatexp, timep,factor,num;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
        if(combatexp<10000)
        {
message_vision("������$N����һ������������С��ɫ���������������\n",me);
             return 1;
        }
        if ((int)me->query_condition("hxsd_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }

	if(combatexp>2000000)
        {
message_vision("������$N����һ�����������书̫���ˣ��Ѿ�û���ʺϸ���������ˡ���\n",me);
             return 1;
        }


        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
message_vision("������$N����һЦ����������������ˣ�\n", me);
message_vision("�������$Nһ��˵������Ҫ��û���£����õ�����ó������ñ����ȥ�������塣\n",me);
                   return 0;
             }
             else
             {
message_vision("��������$N̾��һ�����������Ҿ��ٸ���һ�λ���ɡ�\n", me);
                   me->delete("songxin");
                   me->add("qi",-(int)(me->query("qi")/10));
             }
        }

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];
        quest = QUESTS_D(tag)->query_quest();
        timep = quest["time"];

        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
             tell_object(me,"�����Ұѡ�"+quest["quest"]+"������ɱ�ˣ���Ĳ�ʹ�Ժ���˵��\n" NOR);

        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];

        me->set("quest", quest);
//                   if (ob = present("xin", this_player()))
//                   {
//                   destruct(ob);     
//                   }
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
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

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW "�����Ը�����������" + time + "��");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                   message_vision("����Ц�������ҿɾͲ������ˡ�\n",who);
                   return 1;
             }
             if (who->query("songxin") > 0)
             {
                   message_vision("����һ�����ǽӵ�����������ô���������ȡ��������û�գ�\n",who);
                   return 1;
             }
             else
             if ( ob->value() < 2000)
             {
message_vision("����һ˫�������۾�ֱ����$N�����Ǯ�ɲ������ǵĿ�����\n", who);
                   return 1;
             }
             else
             {
message_vision("����Ц�����Ǻã������������������ڡ����ֲ�ʹ�����Ұɣ�\n",who);
                                      who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   who->apply_condition("menpai_busy",5);
                   who->apply_condition("hxsd_busy",1+random(5));
                   return 1;
             }
        }
        return 1;
}
