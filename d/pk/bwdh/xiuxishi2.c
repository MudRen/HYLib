//xiuxishi.c ��Ϣ��

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIR"��Ϣ��"NOR);
        set("long", @LONG
�����Խ�ɽׯ����Ϣ�ң�ƽ������һƬ����֮����������ϰ������ׯ����
���ӹ̼ܽ�Ϊ�ϸ�Ҳ����Ϊ��ˣ����µ����书�󶼲���������Ʒ�ж�����
����֮��Ī����������ʱ��Ϣ����ȴ����һ�ˣ�����д��·�����
LONG
        );
        


        set("no_fight",1);
     
        setup();
}

