
inherit ROOM;
void create()	
{
	set("short", "��վ");
	set("long", @LONG
�����Ƕ������վ�������������ս�������Ѿ����˶��岻��ȱ��
����Ҫ�ط���ͻ�ʵĵ���ƽʱ�󲿷ֶ���������Ϣ�����ϻ����ż�����
������ȣ��Ա߻��м��Ŵ�����ͷ���ż����̲衣���̲衣
LONG);
      set("exits",([
   
         "southeast":__DIR__"guoshifu",                
	]));
	set("resource/water",1);
	set("sleep_room",1);
	set("objects",([
	  __DIR__"npc/obj/yangtui":4,
	  ]));
       setup();

}
