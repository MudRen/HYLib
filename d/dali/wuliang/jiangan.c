// Room: jiangan.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��������ɽʯ��С·Ҳûһ�����߸߰˵͵��߳��߰���أ�����һ��Ұ��
���������Ͻ�ʵ���ۡ�������ʮ����ż���һ��С��������С����ȥ������
���˹����������ţ�ֻ���ű�ʯ�Ͽ��š����˶ɡ��������֡� 
LONG
        );
        set("exits", ([
            "north" : __DIR__"tiesuo",
            "west" : __DIR__"anbian1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "����");

        setup();
        replace_program(ROOM);
}
