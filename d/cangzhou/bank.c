inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ����
LONG
        );

        set("exits", ([
                "west" : __DIR__"beijie1",
        ]));

        set("objects", ([
                __DIR__"npc/jiang" : 1,
        ]));
        setup();
}
