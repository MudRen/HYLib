//room: /d/tangmen/jiaolou1.c
// by HEM 
inherit ROOM;

void create()
{
  set("short","������¥");
  set("long",
      "�����Ƽұ���������¥�������������Ժգ������Ӵ󣬵���Ҳ���в��١�\n"
      "Ϊ�����ͻϮ���������ܶ��������Ľ�¥����һ����ʿ�����Ѳ�ߡ�\n"
     );

  set("exits",([
       
	"eastdown" : __DIR__"huayuan4",
	
	]));
	set("objects", ([
		__DIR__"npc/longzuwushi" : 4,
	]));

 setup();
 replace_program(ROOM);
}
