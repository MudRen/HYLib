//Cracked by Roath
// Write by Wzfeng@xkx 2000 3-2 
// Modified by Sure 9/2000
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIM"�ʻ���"NOR);
                set("long", @LONG
�������½����ŵ�һ���ʻ��꣬���ڰٻ���ţ��������ҡ�����������֣�
ȴҲ��使�����Ρ��������ڴ������ʺ���ĬĬ��ף�����������˼���
С����Ӣ���ֳֻ������ڻ��������߶�������������ÿ���ʻ����ű߹�̨�ϻ�
����һ�Ÿ�ʾ(gaoshi)��
LONG
        );
        
        set("no_fight", 1);
        set("exits", ([
                       "east" : __DIR__"chaguan",
                        ]));
             set("item_desc", ([
                        "gaoshi":
                    "������������������������������"+HIG"������֪"NOR+"������������������������������������\n"
                        "�� һ�������ﻨ���ļ۸��ã�list)�鿴���򻨿�ֱ�����������buy)        �� \n"
                        "�� �������ʻ����ṩ�ͻ�������������Ů��ѯ(ask ying lian about songhua)�� \n"
                        "�� ��������(help flower)����ѯ���京������ϡ�                          �� \n"
                        "�������������������������������������������������������������������������� \n\n"
                        ]) );
        set("objects", ([
                __DIR__"npc/hua_girl" : 1,
        ]));
            set("no_fight",1);
            set("no_sleep",1);
            setup();

}
