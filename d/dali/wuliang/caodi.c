// Room: caodi.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "��ٹȹȿ�");
        set("long", @LONG
��ǰ��Ƭ�ݵأ���ͷ����ȫ��һ�����������߹��ݵأ�ֻ��һ���������
����������������һƬ�����ϰ��ᣬд�žŸ����֣����ն�����˹�ɱ��
�⡱�����ֺ�ɫ���ǡ�ɱ����ȴ�����֮ɫ�� 
LONG
        );
        set("exits", ([
            "out" : __DIR__"hslin",
            "south" : __DIR__"xiaojing",
        ])); 
        set("outdoors", "����");

        setup();
        replace_program(ROOM);
}
