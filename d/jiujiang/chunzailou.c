inherit ROOM;

int do_install(string arg);

void create ()
{
  set ("short","����¥");
  set ("long", @LONG
�����ǾŽ��Ĵ�԰�ԵĴ���¥�������ǾŽ��������ļ�Ժ�������
Ů���䲻�Ϲ�ɫ���㣬��Ҳ�Ƶ����ǳ��������ˡ��м������û�֦��
չ��Ů�������ſ��к��ſ��ˡ�����ķ��䲻ʱ������Ц������������
¥�����滹��һ��С���꣬��Ӧ������ɫ����ʳ��
LONG);

  set("exits", ([ 

  "down":__DIR__"chunyuan",
         ]));
  set("objects",([
     __DIR__"npc/jiuke":1,
     __DIR__"npc/jianke":1,
     __DIR__"npc/zhanggui":1,
     __DIR__"npc/girl":1,
     	__DIR__"npc/xiang":1,
     ]));
  set("valid_startroom", 1);
  setup();
 
}

