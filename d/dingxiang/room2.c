// room1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������г����ª����ר��Ϊ����Ŀ��˴���õġ��м��С��
ľ���ϸ��˼����ߺ���Ʈ���������˵�������
LONG
        );
        set("exits", ([
            
            "southeast" : __DIR__"shop",
        ]));
        

        setup();
        replace_program(ROOM);
}
