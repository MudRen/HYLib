//changlang3.c ����
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIY"���᳤��"NOR);
            set("long",@LONG
���Ƕ������Ⱦ�ͷ������ͨ���鷿��һ�����ɵ��ӵ������ֹ����û�й�
�������������ɵ��Ӳ��ܽ��鷿��
LONG
    );

            set("exits",([
                "east": __DIR__"shufang",
                "west": __DIR__"lang2",
            ]));             
	    setup();
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("gsz_agree")
           && dir =="east")
	return notify_fail("�����Ǿ���ȵĽ��أ�û��ׯ����������ɵ��Ӳ��ܽ��룡��\n");
        return ::valid_leave(me, dir); 
}
