// caoyuan3.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ�
�治���ߣ�������ƥ�����������ǵĺ����⡣���߿��Կ�����ԭ������
��ȥ����ɳĮ�ˡ�
LONG);
        set("exits", ([
            "southdown" : __DIR__"caoyuan2",
            "northwest" : __DIR__"shop",
            "southeast" : __DIR__"road1",
            "eastdown" : __DIR__"caoyuan",
            "northeast":__DIR__"caoyuan6",
          "west" : "/d/xinjiang/zhenlong",	
        ]));
        set("outdoors", "dingxiang");
        setup();
        replace_program(ROOM);
}
