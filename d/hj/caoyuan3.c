// caoyuan3.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣���߿��Կ���������������
��ȥ����ɳĮ�ˡ�
LONG);
        set("exits", ([
            "southdown" : __DIR__"caoyuan2",
            "northwest" : __DIR__"shop",
            "northup" : __DIR__"road1",
            "eastdown" : __DIR__"caoyuan",
        ]));
        set("outdoors", "gaochang");
        setup();
        replace_program(ROOM);
}
