//dadi.c ����ʹ
// [lsg 1999/11/24]

inherit NPC;
#define QUEST_KILL __DIR__"quest"  
string ask_me();
#include <ansi.h>;
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
        "�ྩ����","������","���𵺺�̲","���Ṭ","���տ���ɽ",
        "�����","��ӹ��","����Ͽ","ů��","�ʹ�����",
        }),
        });
int time_period(int timep,object me);
void create()
{
        set_name(HIR"ָ��ʹ"NOR, ({ "zhihuishi", "shi", "renwu"}));
        set("title", HIW"��Ұ���"NOR);
        set("gender", "����" );
set_temp("no_kill",1);
set("no_get",1);
        set("age", 82);
        set("str", 900);
        set("int", 225);
        set("con", 230);
        set("dex", 250);
        set("per", 230);
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
              "job"  : "���ɵ��ӿ�����������job��Ϊ�������¡�\n",       
                "����" : (: ask_me :),
          "liangong" : (: ask_me :),
]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}
void init()
{
        add_action("do_work", "liangong");
        add_action("give_quest", "job");
}

int give_quest()
{
        mapping quest ;
        object me;
        int combatexp, timep;
        string room;
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
                if (me->is_busy())
                        return notify_fail("����æ���ء�\n");
                if (this_object()->is_busy())
                        return notify_fail("����æ���ء�\n");


        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if (me->query("playerjob")==1)  
            {
                      message_vision("$N����$n˵:�����ϵ�����û�����!\n", this_object(), me);
                      return 1;
            }
        if(combatexp<100000)
        {
tell_object(me,"\nָ��ʹ˵��������书������....��\n");
             return 1;

        }

        if(me->query("questjob"))
        {
tell_object(me,"ָ��ʹ������һ��˵��������һ������û�����!\n");
             
        }

if (random(2)==1
||me->query_temp("roomjob"))
{
        quest = QUEST_KILL->query_quest();
             tell_object(me,HIR"��"+quest["quest"]+HIC"����������ǲ�����ȥ��ѵ����һ�¡�\n" NOR);

        me->set("questjob", quest["quest"]);
        me->set("playerjob", 1);
        return 1;
}
else {
	  room=rooms[0][random(205)];
          me->apply_condition("roomjob",8);
	  me->set_temp("roomjob",room);
	  tell_object(me,HIG"����˵�ڡ�"HIR+room+HIG"����������һЩ�����¼���\n"+
           "��Ͽ�ȥ��"HIY+room+HIG"����̽(citan)һ�°ɡ�\n"+
           "·�϶��С�ġ�\n"NOR);
return 1;
}
}


int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("questjob"))
             {
                  tell_object(who,"û�ҵ��������������������ĵ��Ӱ�æ���ˣ�\n");
                   who->apply_condition("menpai_busy",4+random(8));
                   who->set("questjob",0);
                    who->delete("questjob");
                   who->delete_temp("roomjob");
                   who->set("playerjob", 0);
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"ָ��ʹ���˿�$P��������Ǯ˵����̫���ˣ���ô����Ҳ����˼�ó��֣�\n");
                   return 1;
             }
             else
             {

tell_object(who,"ָ��ʹ˵�����ðɣ���ξ����ˣ��²�Ϊ����\n");
                   who->apply_condition("menpai_busy",4+random(8));
                   who->set("questjob",0);
                   who->delete("questjob");
                   who->delete_temp("roomjob");
                   who->set("playerjob", 0);
                  return 1;
             }
        }
        if(!who->query("questjob"))
        {
             tell_object(who,"ָ��ʹ˵������û�н������°���\n");
             return 0;
        }

	if( userp(ob) ) {
        tell_object(who,"ָ��ʹ��ð���ɣ�����ʲô������Ŀ����ѽ�������������ˣ�\n");
        return 0;
        }

	if( !ob->is_character() ) {
        tell_object(who,"ָ��ʹ��ð���ɣ�����ʲô������Ŀ����ѽ�������������ˣ�\n");
        return 0;
        }

        if( ob->query("family/family_name") != who->query("questjob"))
        {
        tell_object(who,"ָ��ʹ˵������ʲô������Ŀ����ѽ�������������ˣ�\n");
        return 0;
        }

        else
        {
             tell_object(who,"ָ��ʹ���˵�˵�������úã�����˱��š���\n");
             exp = 200 + random(200);
             pot = 150 + random(150);
             score = 10 + random(15);

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
             tell_object(who,HIW"��ϲ�������˱��ŵ�Ӱ�죡\n"NOR);
             tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬\n"+ chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(score)+"�㽭��������\n"NOR);
             who->set("questjob", 0 );
             who->delete("questjob");
             who->set("playerjob", 0);
this_object()->start_busy(4);
who->start_busy(3);
	if( ob->is_character() ) {
       call_out("destroying", 0,ob);                              
	}
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
	say( "ָ��ʹ��Ц��˵�������޵в����棡\n");
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
int do_work()
{
        object me, ob, weapon;
        me=this_player();

if (me->query("qi") <30)
                return notify_fail("����������ˡ�");
if (me->query("jing") <30)
                return notify_fail("��ľ������ˡ�");

        if (me->query_temp("player_working")) {
                if (me->is_busy())
                        return notify_fail("����æ���ء�\n");

                tell_object(me, HIC"���ָ��ʹһ��һʽ�Ķ�����������\n"NOR);

                        message_vision(HIR"$N��һȭ����һ�ƣ���Ĵ����졣\n"NOR, me);
                        me->add("jing",-me->query("max_jing")/50);
                        me->add("qi", -me->query("max_qi")/50);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);

                if (me->query_temp("working_times")>=me->query_temp("player_working"))
                {
                        message_vision(HIC"ָ��ʹ��$N���ͷ�������˵�������ˣ����ˣ��������������ɡ�\n"NOR, me);
                        message_vision(HIG"ָ��ʹ��$N�����Ĵָ������������㣬�������ܳɲġ�\n"NOR, me);
                        me->delete_temp("working_times");
                        me->delete_temp("player_working");
                        me->add("combat_exp", random(22)+18);
                        me->add("potential", random(12)+16);
                        me->start_busy(3);
                }
                return 1;
        }
        return 0;
}

string ask_me()
{
        object me;
        me=this_player();

        if (me->query_temp("player_working"))
                return "�㲻�Ǻ���������";

                if (me->is_busy())
                        return "����æ���ء�";

        me->set_temp("player_working",random(20)+10);
        me->set_temp("working_times",0);
        return "���Ҿ���������(liangong)�ɡ�";
}
