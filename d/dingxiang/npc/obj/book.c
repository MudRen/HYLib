
inherit ITEM;

void create()
{
   set_name("������ǹ�����š�", ({ "spear book","book" }));
   set_weight(200);
   set("unit", "��");
   set("long","����һ�����ܻ���ǹ������.\n");
   set("no_drop",1);
   set("no_give",1);
   set("no_steal",1);
   set("skill", ([
     "name":      "spear",    
     "exp_required":   0, 
                         
     "sen_cost":     10,   
     "difficulty":   1, 
     "max_skill":200,          
   ]) );
}
