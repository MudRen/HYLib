//changlang2.c ����
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIY"���᳤��"NOR);
            set("long",@LONG
���붫�᳤�ȣ���������ľ���һ��ҩ�ݵ���ζ��ԭ���Ǵӱ���ĵ���ɢ
�������ģ�����������ϲ���ĵط���ƽʱ�������˸����롣���洫�������ߺ
����������Ǿ���ȵ����������ˡ�
LONG
    );

            set("exits",([
                "north": __DIR__"danfang",
                "south": __DIR__"lgf",
                "east": __DIR__"lang3",
                "west": __DIR__"lang1",
            ]));            

	    setup();
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("gsz_agree")
           && ( dir =="north" || dir=="south"))
        return notify_fail("�����Ǿ���ȵĽ��أ�û��ׯ����������ɵ��Ӳ��ܽ��룡��\n");
        return ::valid_leave(me, dir); 
}
