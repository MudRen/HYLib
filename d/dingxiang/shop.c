// shop.c ��ԭ��

inherit ROOM;

void create()
{
        set("short", "��ԭ��");
        set("long", @LONG
���ǲ�ԭ�е�һ�����У�����Ҳ�ǲ�ԭ�и�������ļ�ɢ�أ�ֻ
�ʻ���ĺû������ʻ������Դ����Ȼ˵�Ǹ����ж����ɿ��̵�������
��ɡ�
LONG);
        set("exits", ([            
						"southwest":__DIR__"dongmen",
            "east" : __DIR__"room1",
            "northwest" : __DIR__"room2",
            "southeast" : __DIR__"caoyuan3",
        ]));        
          set("objects",([
          __DIR__"npc/shang":1,
          __DIR__"npc/ji":3,
          ]));

        set("outdoors", "dingxiang");
        
        setup();
        replace_program(ROOM);
}
