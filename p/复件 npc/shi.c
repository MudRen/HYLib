//dadi.c ����ʹ
// [lsg 1999/11/24]

inherit NPC;
#include <ansi.h>;
#include "teamjob.c"
int time_period(int timep,object me);
mixed rooms = ({
        ({
        "���ֹ㳡","����·","������","������Ϊ��","����������",
        "��΢��","����ƺ","��ѩɽɽ��","������","ȫ��̴���", 
        "Ĺ��","�һ�ɽׯ����","�����̴���","������","���޺�", 
        "ѩɽ��ɽ��","һƷ�ô�Ժ","������ɽ��","������","��ָ��", 
        "��ȸ����","��������","�׻�����","��������","�찲��",
        "�������","�����ھ�","�����","������","Ȫ������",
        "��������","�������","����¥","������","��ɽ����",                
        "�߹���","�����ַ�","��������","ϲ�ݳ�","��³��", 
        "����","ɽ����","����ͷ","�������","��ɽ����",
        "����Ժ","ӿȪ��","������","���Ϸ�","�Ͻ��",
        "�ɷ��","����ɽ��","������","����̶","���ɷ�",                
        "��Ӧ��","�����","������Ժ","������","������", 
        "��������","������","�һ�����","�嶾�̴���","������",
        "������","˿��֮·","�������","�ڷ��","���ŷ�",
        "�ϳ�","��Ҥ��","��Ȼ��"," ��ľ�沿��","��ľ��Ӫ��",
        "�ɹŲ�ԭ","���岿��","СϪ��","���ݸ�","���������",
        "������","���ݳ�"," ������","ɽ����","��ݮ��",
        "�����ַ�","ʮ�ֽ�ͷ","����������","�ָ�ʫ��","佻�Ϫ",
        "�سǾ�¥","��ţ���","������","��گ�»���","������",
        "�����","���ƺ���","³����","ϲ�ݳ�","̫�ͽֿ�",
        "��³��","ʥ��","���ǹ�","��ѩɽ��´","���϶�",
        "������","ʮ����","��ɽ���","Ӣ�ۻ��","������",
        "�����ھ�","�ų���","��������լ","����ɽ����","��ˮ̶",
        "̫��","�����","������","��������","������",
        "������","ʥ����","�����ô���","�ɵµ�","ƽ����",
        "���Է�","������","������","��������","������Ժ",
        "��̳��","��ȳ�","Ⱥ�ɹ�","������","ɯ��ƺ",
        "�����","����","�ƺӰ�կ��","������ԭ","���",
        "������ջ","������ջ","̫�͵�","̩�͵�","���ĵ�",
        "��ʦ��","�ɷ��","Ȫ������","�����̴���","������Ժ",
        "��������","��ɽׯ","����ͤ","�Ͻ���","��ɽ��",
        "��ʶ�","��ڷ�","�һ���","����̨","�嶼����",
        "���׽���","�䵱������","���湬","��������","���칬",
        "�۾�¥","����̨","����ʹ����","����������","��ȸ������",
        "���¶�","��ң��","ѩɽ��̳","ѩɽ��ɽ��","����̨",
        "������","����ˮ�","�������","����Ժ","������",
        "����ɽ��","�չ���","����������","ף�ڵ�","������",
        "��翷�ɽ��","������","����С��","����ɽ��","ӭ��Ƶ�",
        "��ָ��","��ָ��","������","Ĵָ��","̫�׾�¥",
        "ʢ������","������","���𵺺�̲","���Ṭ","���տ���ɽ",
        "�����","��ӹ��","����Ͽ","ů��","�ʹ�����",
        }),
        });
void create()
{
        set_name("����ʹ", ({ "renwu shi", "shi", "renwu"}));
        set("title", HIG"��Ұ���"NOR);
        set("gender", "����" );
        set("age", 102);
        set("str", 50);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("long", 
"һλ������ʹ��ר�Ÿ�������ɵ��Ӹ�������.\n");
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
 	      "��������"  : (: ask_jianxi :),
 	      "teamjob"  : (: ask_jianxi :),
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
        mapping quest,item,npc;
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
        
                        if(me->query_temp("jobitem"))
        {
tell_object(me,"\n����ʹЦ��˵�������ȰѸղ������ҵĶ����ҵ����˼Ұ�....��\n");
             return 1;
        }
                if(me->query_temp("roomjob"))
        {
tell_object(me,"\n����ʹЦ��˵�������ȰѴ�̽�������ð�....��\n");
             return 1;
        }
        
        if ((int)me->query_condition("roomjob")){message_vision("$N����$nҡ��ҡͷ˵����սӹ���̽����!�Ȼ�����!\n", this_object(), me);return 1;}

        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if(combatexp<10000)
        {
tell_object(me,"\n����ʹЦ��˵��������书������....��\n");
             return 1;

        }

        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
tell_object(me,"����ʹ������һ��˵�����Ҹղ�Ҫ���ҵĶ����أ�\n");
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


        if (random(3) == 0)
        {
     quest = QUESTS_D(tag)->query_quest();
	}
       else
        if (random(3) == 1)
        {
     quest = QUESTH_D(tag)->query_quest();
	}
       else
        if (random(3) == 2)
        {
     quest = QUESTW_D(tag)->query_quest();
	}
       else
{
	  room=rooms[0][random(205)];
          me->apply_condition("roomjob",8);
	  me->set_temp("roomjob",room);
	  tell_object(me,HIG"����˵�ڡ�"HIR+room+HIG"����������һЩ�����¼���\n"+
           "��Ͽ�ȥ��"HIY+room+HIG"����̽(citan)һ�°ɡ�\n"+
           "·�϶��С�ġ�\n"NOR);
return 1;
}

if (random(15)==0)
{
item  = QUESTW_D(tag)->query_quest();
npc = QUESTS_D(tag)->query_quest();
if (random(2)==1)
npc = QUESTH_D(tag)->query_quest();
me->set_temp("jobitem",item["quest"]);
me->set_temp("jobnpc",npc["quest"]);
me->apply_condition("roomjob",8);
tell_object(me,HIC"�ѡ�"HIG+item["quest"]+HIC"���ҵ�����������"HIG+npc["quest"]+HIC"����\n" NOR);
return 1;
}

        timep = quest["time"];if (!quest["time"]) timep=400;

        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
             tell_object(me,"�ѡ�"HIR+quest["quest"]+HIC"��ɱ�ˣ����Ա��ɲ�����\n" NOR);
        else
             tell_object(me,"�һء�"HIG+quest["quest"]+HIC"������Ա������á�\n" NOR);
if (me->query_temp("menpaijob") < 0)
me->delete_temp("menpaijob");
me->add_temp("menpaijob",1);
if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+me->query_temp("menpaijob")+NOR"���������ˡ�\n" NOR);
if (me->query_temp("menpaijob") > 160)
{
tell_object(me,"�����Ĳ�����Ľ�������������!\n" NOR);tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+me->query("mpgx")+NOR"����\n" NOR);me->add("mpgx",1);
me->add("score",200);
me->delete_temp("menpaijob");
}
             quest["time"]=300;
             quest["exp_bonus"]=200+(int)me->query_temp("menpaijob");
             quest["pot_bonus"]=140+me->query_temp("menpaijob")/2;
             quest["score"]=50;
        me->set("quest", quest);
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

        tell_object(me,HIC "����ʹ˵�����������" + time + "��");
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
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"����ʹ���˿�$P��������Ǯ˵����̫���ˣ���ô����Ҳ����˼�ó��֣�\n");
                   return 1;
             }
             else
             {

tell_object(who,"����ʹ˵�����ðɣ���ξ����ˣ��²�Ϊ����\n");
                   who->apply_condition("menpai_busy",3+random(4));who->delete_temp("menpaijob");
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                  return 1;
             }
        }
        if(!(quest = who->query("quest")))
        {
             tell_object(who,"����ʹ˵�������㶺�ˣ���Ҫ�Ĳ��������\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
        tell_object(who,"����ʹ��ð���ɣ�����ʲô������Ŀ����ѽ�����������Ϸ��ˣ�\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"����ʹ˵�����Բ���ʱ����ˣ���ĵ��Ӹհѻ�������ˣ�\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"����ʹ���˵�˵����̫���ˣ��Ҿ���Ҫ����������б��£�\n");
             exp = 50 + random(100)+(int)who->query_temp("menpaijob")/2;
             pot = 20 + random(30)+(int)who->query_temp("menpaijob")/3;
             score = 2 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
//             if( bonus > 300) bonus = 300;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"��ϲ�������һ������\n"NOR);
             tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬\n"+ chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(score)+"�㽭��������\n"NOR);
             who->set("quest", 0 );
             who->start_busy(3);
             return 1;
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
	say( "����ʹ��Ц��˵�������޵в����棡\n");
	command("hehe");
}

void die()
{
	unconcious();
}
