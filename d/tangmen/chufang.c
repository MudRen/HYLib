//ROOM: /d/tangmen/chufang.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
     ���������ŵĳ��������󴨲˶��ص���ζ�˱Ƕ��������˾���ס��ˮ������
���°��ˡ���˵���ŵĳ�ʦ���껹����������רΪ�ʵ��϶��󴨲ˡ����й��Ŵ�����
�������Ǵ�������Ҫ�ĵ�ζƷ��
LONG
     );
	set("exits",([
		"south" : __DIR__"duanmuting",
  ]));
	set("objects",([
		__DIR__"npc/wangsao" : 1,
		__DIR__"obj/shan" : 1,
		__DIR__"obj/roupian" : 3,  
  ]));
 
 setup();
 replace_program(ROOM);
}