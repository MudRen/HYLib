// Room: /d/xiangyang/conglin3.c

inherit ROOM;


void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����Ѿ��������˵��㼣�ˣ�ֻ��һЩ���ӵ�Ұ�޽�ӡ��·Խ
�����ͣ�һ������������Ͳ�����ǰ���ˡ�
LONG	);
	set("exits", ([  
        "eastdown" : __DIR__"conglin2",
         "westup" : __DIR__"conglin4",
         "east" : "d/migong/migong1",
        ]));
        set("objects",([
              "/d/heimuya/npc/snake" : 1,
        ]));      
	 
        set("outdoors", "xiangyang");
	setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "westup") && (dir != "eastdown"));
         if ((userp(me)) && (dir == "westup")){
            me->receive_damage("jing", 90); 
            me->receive_damage("qi", 50);       
            write("���͵�ɽ´�������ĸг�����һ����ͺ���䤱���\n");
    }

        if ((userp(me)) && (dir == "eastdown")){
        me->receive_damage("jing", 90);    
        me->receive_damage("qi", 50);     
        write("���͵�ɽ´�������ĸг�����һ����ͺ���䤱���\n");
}
        return 1;
}
