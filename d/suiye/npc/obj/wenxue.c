
inherit ITEM;

void create()
{
   set_name("�����־���", ({ "san zi jing","jing","book" }));
   set_weight(600);
   set("unit", "��");
   set("long","����Ϊ������Ļ���������.\n");
   set("value", 300);
   set("skill", ([
     "name":      "literate",    
     "exp_required":   0, 
                         
     "sen_cost":     10,   
     "difficulty":   1, 
     "max_skill":   20,          
   ]) );
}
