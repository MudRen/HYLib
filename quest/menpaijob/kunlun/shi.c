//dadi.c ����ʹ
// [lsg 1999/11/24]

inherit NPC;
#define QUEST_KILL __DIR__"quest"  
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
        set_name("����", ({ "zhang lao", "zhang", "lao"}));
        set("title", HIG"������"NOR);
        set("gender", "����" );
        set("age", 82);
        set("str", 950);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("long", 
"һλ�ĳ��ϡ�ר�Ÿ�������ɵ��Ӹ�������.\n");
        set("combat_exp", 50000000);
        set("shen_type", 1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        
        set_skill("force", 300);
        set_skill("zhemei-shou", 300);
        set_skill("unarmed", 500);
        set_skill("xiantian-qigong", 500);

         map_skill("unarmed","zhemei-shou");
       map_skill("force","xiantian-qigong");
        
        set("inquiry", ([
              "job"  : "���ɵ��ӿ�����������quest�����������Ҳ���Ϊ�����ǵġ�\n",       
]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}
void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num;
        string room;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
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

        if( me->query("family/family_name") != "������")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if (me->query("kunlun_job")==1)  
            {
                      message_vision("$N����$n�����ϵ�����û�����!�ѵ������Ҫ�ҵ��˸�ɱ��?\n", this_object(), me);
                      return 1;
            }
        if(combatexp<10000)
        {
tell_object(me,"\n�����ɳ���Ц��˵��������书������....��\n");
             return 1;

        }

        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
tell_object(me,"�����ɳ��ϵ�����һ��˵�����Ҹղ�Ҫ���ҵĶ����أ�\n");
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                   return 0;
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


        if (random(2) == 0)
        {
     quest = QUESTS_D(tag)->query_quest();
	}
       else
        if (random(2) == 1)
        {
     quest = QUESTH_D(tag)->query_quest();
	}
       else
     quest = QUESTS_D(tag)->query_quest();
        timep = quest["time"];

        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
             tell_object(me,"�ѡ�"+quest["quest"]+HIC"�����������뿴������ʲôģ����\n" NOR);
        else
             tell_object(me,"�һء�"+quest["quest"]+HIC"������Ա������á�\n" NOR);

        me->set("quest", quest);
        me->set("kunlun_job", 1);
        me->set("task_time", (int) time()+(int) quest["time"]);
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

        tell_object(me,HIC "�����ɳ���˵�����������" + time + "��");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                  tell_object(who,"û�ҵ��������������������ĵ��Ӱ�æ���ˣ�\n");
                   who->apply_condition("menpai_busy",7);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   who->set("kunlun_job", 0);
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"�����ɳ��Ͽ��˿�$P��������Ǯ˵����̫���ˣ���ô����Ҳ����˼�ó��֣�\n");
                   return 1;
             }
             else
             {

tell_object(who,"�����ɳ���˵�����ðɣ���ξ����ˣ��²�Ϊ����\n");
                                      who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob"); 
                  who->apply_condition("menpai_busy",7);
                   who->set("quest",0);
                   who->set("kunlun_job", 0);
                  return 1;
             }
        }
        if(!(quest = who->query("quest")))
        {
             tell_object(who,"�����ɳ���˵�������㶺�ˣ���Ҫ�Ĳ��������\n");
             return 0;
        }

	if( !ob->is_character() ) {
        tell_object(who,"�����ɳ��ϻ�ð���ɣ�����ʲô������Ŀ����ѽ�����������Ϸ��ˣ�\n");
        return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
        tell_object(who,"�����ɳ��ϻ�ð���ɣ�����ʲô������Ŀ����ѽ�����������Ϸ��ˣ�\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
                                      who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
             tell_object(who,"�����ɳ���˵�����Բ���ʱ����ˣ���ĵ��Ӹհ��Ǹ��һ��ץ����\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"�����ɳ��ϸ��˵�˵����̫���ˣ��Ҿ���Ҫ����һ�����б��£�\n");
             exp = quest["exp_bonus"] + 300;
             pot = quest["pot_bonus"] + 260;
             score = quest["score"] + random(20);

//             exp = 200 + random(250);
//             pot = 100 + random(150);
//             score = 10 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
//             if( bonus > 100000) bonus = 100000;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
who->start_busy(3);
             tell_object(who,HIW"��ϲ�������һ������\n"NOR);
             tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬\n"+ chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(score)+"�㽭��������\n"NOR);
             who->set("quest", 0 );
             who->set("kunlun_job", 0);
	if( ob->is_character() ) {
       call_out("destroying", 0,ob);                              
//   1    remove_call_out("destroying");
//             destruct(ob);
	}
//             return 1;
}
        return 1;
}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "�����ɳ�����Ц��˵�������޵в����棡\n");
	command("hehe");
}

void die()
{
	unconcious();
}

void destroying(object ob)
{   
   destruct(ob);
}