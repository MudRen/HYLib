#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"����"NOR); 
        set("long", @LONG
������͹������ɽ�ֵ�����������󣬿����Ż�ѩ������������ǰ����ϲ��
����ɽ��壬��������ѩ�ǣ�ֻ����һ�������ɽ�壬��Ϊ��������紵�Σ�ɽ��
��´��Ҳ����������·�˵���һ��ɽ�£���ѩ���紵�øɸɾ�����¶�����ɫ����
ʯ������Χ��ɫ�󲻵��ͣ����������į֮�У����˾�Ȼ���壡                         
LONG); 
        set("type","street");
        set("exits",([
        "up":__DIR__"bingao0",
        ]) );
        set("outdoors", "guanwai");
        set("coor/x",-1280);
        set("coor/y",-110);
        set("coor/z",700); 
        setup();
} 
int valid_leave(object me, string dir)
{
        int dam_gin,dam_sen,dam_kee;
        dam_gin = me->query("max_jing")/6;
        dam_sen = me->query("max_jing")/6;
        dam_kee = me->query("max_qi")/6;
        if( userp(me) && dir == "up" )
        {
                if ( me->query_skill("dodge") < 180 ) {
                        if ((int)me->query("qi") <= 50) {
                                message_vision("ɽ���羵������Ƶ�������δ��֮�䣬$N��������һ�գ�ˤ������......\n\n",me);
                                me->unconcious();
                        }
                        else {
                                me->start_busy(5);
                                me->receive_damage("qi",50);
                                message_vision("ɽ���羵������Ƶ���$Nֻ�������޸������㲻��......\n\n",me);
                        }
                        return notify_fail("\n");
           }
                else {
                    switch ( random(14) ) {
                        case 1:         
                                if ((int)me->query("jing") < dam_gin || (int)me->query("qi") < dam_kee || (int)me->query("sen") < dam_sen) {
                                        message_vision(HIW"$NͻȻ���ý��������������Ĵ��������죬�ŵ�һ������������ˤ����ȥ��\n"NOR,me);
                                        me->unconcious();
                                }
                                else {
                                        me->receive_damage("qi", dam_gin);
                                        me->receive_damage("qi", dam_kee);
                                        me->receive_damage("jing", dam_sen);
                                        message_vision(HIW"$NͻȻ���ýŵ�һ����������ˤ��һ�ӡ�\n"NOR,me);
                                }
                                return notify_fail("\n");
                                break;
                        case 2:
                                message_vision(HIW"��Ȼ֮�䣬�����޴�ı������ң��ڿ���к�Х��ը�ѣ�����ǵ���$Nͷ��������������\n\n"NOR,me);
                                if ( random(2) )
                                {
                                        message_vision(HIW"һ��޴���ƥ�ı�ʯ�������������$N�Ķ�ǣ����䡣������\n"NOR,me);
                                        me->unconcious();
                                }
                                else
                                {
                                        message_vision(HIW"$Nȫ����������ʯ�£�����ץ��͹�����ı������ڶ�����飬ȴ���ɵþ���һ���亹��\n\n"NOR,me);
                                }
                                return notify_fail("\n");
                                break;
                        case 3:
                                message_vision(HIW"ļ�ء���¡��һ�����죬ɽҡ�ػΣ���������ɽ���ˣ�\n\n"NOR,me);
                                me->unconcious();
                                return notify_fail("\n");
                                break;
                        case 4:
                                message_vision(HIW"Զ���������������죬���������������������ͣ�ת˲֮�侹\nȻ��һ�����������ѩ���ɽ�Ϲ��£�\n\n"NOR,me);
                                message_vision(HIW"\n$N��ܲ���������ѩ�������ѹ���±ߣ�\n\n"NOR,me);
                                if( me->query_kar()<12 || me->query_per()<12 )
                                {
                                        message_vision(HIW"$N������ѹ�ڱ���֮�У�ѪҺ���ѱ���������ǰֻ�ǰ�ââ��һƬ....\n\n"NOR,me);
                                   me->die();
                                }
                                else if ( me->query_kar()<16 || me->query_per()<16 )
                                {
                                        message_vision(HIW"$N������˿�������β�סϡ���Ŀ�����������ģ������....\n\n"NOR,me);
                                        me->unconcious();
                                }
                                else
                                {
                                        message_vision(HIW"$Nҧ�����أ��þ�ȫ����ѩ���⼷��һ�磬����......\n����$N��ѩ����ҡҡ�λ����˳���......\n\n"NOR,me);
                                        me->start_busy(3);
                                }
                                return notify_fail("\n");
                                break;
                        }       
                }
        }
        return 1;
}