#include <ansi.h>
inherit ROOM;

void create ()
{
set("short",HIR "[1;31m���з����߹����ҡ�[2;37;0m"NOR);

set("long",@LONG
���������з��ļ�,�յ����������һ��С��,�������Ǹ��鷿
������ż�̨����һ���ļһ�,��ϸһ��ԭ����P4������,�ε�
�ڵ���̨���ϰ���һ����Ů����Ƭ,���ÿ������ұ�����,����.
LONG );

        set("exits",([ /* sizeof() == 1 */
                "gc":"/d/city/guangchang",        
               "down":"/d/wizard/wizard_room" ]));
        set("objects", ([
                "/u/freebird/yutu" : 2,
                "/u/freebird/thousand-gold" : 1,       
                "/u/freebird/msgd" : 1,        
        ]));

        set("valid_startroom", 1);
        set("no_suck", "1");
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}