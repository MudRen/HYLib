 inherit ROOM;
void create()
{
        set("short", "ӥ���̺�");
        set("long", @LONG
ӥ��һ��������׿�������ⶦʢ���̺š���Ȼ���ڻ����¶��ң��������⻹��
������һ�����֣��Ӳض������Ĳ��㣬�ӹ��������Ĵ�����˿�У��Ӵ��¯������
��ש������ʲô��ֻҪ�Ǽ�ֵǮ�Ķ�����������������������������̨�Ϸ���һ��
���ӣ��ӣɣǣΣ���
LONG
        );
        
        set("item_desc", ([
                "sign": @TEXT
���̺Ų����ۺ񡣿��Ŀ��������
pawn        �䵱��
value       ���ۡ�
redeem      ��ء�
TEXT
        ]) );
        set("exits", ([
                "west" : __DIR__"octo15",
        ]));
        set("objects", ([
                __DIR__"npc/hu": 1, 
                __DIR__"npc/petowner" : 1,
                ]));
   set("no_fight",1);
        set("coor/x",-1190);
        set("coor/y",20);
        set("coor/z",5);
        setup(); 
} 
void reset()
{
   object ob;
        ::reset();
        if( !ob=find_living("hu") )
                ob=new( __DIR__"npc/hu" );
        ob->move(this_object());
}  
