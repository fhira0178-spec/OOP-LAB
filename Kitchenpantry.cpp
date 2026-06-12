#include <iostream>
#include "KitchenPantry.h"

using namespace std;

void line(const string& title) {
    cout << "\n>>> " << title << "\n";
}

int main() {

    // ══════════════════════════════════════
    // 1. FUNCTION OVERLOADING (Ingredient)
    // ══════════════════════════════════════
    line("Ingredient Constructors");

    Ingredient i1;                                      // Default
    Ingredient i2("Flour", "kg", 2.0, 60.0);      // Full
    Ingredient i3("Sugar", "kg", 1.0, 80.0);
    Ingredient i4("Milk", "liters", 3.0, 40.0);
    Ingredient i5("Butter", "kg", 0.5, 120.0);
    Ingredient i6(i2, 5.0);                             // Copy with new qty

    cout << "Default   : " << i1;
    cout << "Full      : " << i2;
    cout << "Copy(qty5): " << i6;

    // ══════════════════════════════════════
    // 2. FUNCTION OVERLOADING (Pantry)
    // ══════════════════════════════════════
    line("Pantry Constructors");

    Pantry p1;                              // Default
    Pantry p2("Mama's Kitchen", 2000.0);   // Named
    Pantry p3(p2);                         // Copy

    cout << "Default pantry owner : My Kitchen\n";
    cout << "Named  pantry owner  : Mama's Kitchen\n";
    cout << "Copied pantry owner  : Mama's Kitchen (copy)\n";

    // ══════════════════════════════════════
    // 3. ADDING INGREDIENTS
    // ══════════════════════════════════════
    line("Adding Ingredients");

    p2.addIngredient(i2);      // Flour
    p2.addIngredient(i3);      // Sugar
    p2.addIngredient(i4);      // Milk
    p2.addIngredient(i5);      // Butter
    p2.addIngredient(i2);      // Flour again -> auto-merges

    cout << p2;

    // ══════════════════════════════════════
    // 4. OPERATOR OVERLOADING (Ingredient)
    // ══════════════════════════════════════
    line("Ingredient Operators");

    // + : add stock
    Ingredient moreFlour("Flour", "kg", 1.0, 60.0);
    Ingredient totalFlour = i2 + moreFlour;
    cout << "+ (add stock)       : " << totalFlour;

    // - : use up quantity
    Ingredient usedMilk = i4 - 1.5;
    cout << "- (use 1.5L)        : " << usedMilk;

    // * : scale quantity
    Ingredient doubleSugar = i3 * 2.0;
    cout << "* (double qty)      : " << doubleSugar;

    // == : equality
    Ingredient flour2("Flour", "kg", 99.0, 10.0);
    cout << "== (same name?)     : " << (i2 == flour2 ? "Yes" : "No") << "\n";
    cout << "== (different?)     : " << (i2 == i3 ? "Yes" : "No") << "\n";

    // < : compare quantity
    cout << "< (Butter < Flour?) : " << (i5 < i2 ? "Yes" : "No") << "\n";

    // ══════════════════════════════════════
    // 5. OPERATOR OVERLOADING (Pantry)
    // ══════════════════════════════════════
    line("Pantry Operators");

    // + : merge two pantries
    Pantry extraPantry("Store Room", 500.0);
    Ingredient eggs("Eggs", "pieces", 12.0, 15.0);
    extraPantry.addIngredient(eggs);

    Pantry merged = p2 + extraPantry;
    cout << "+ (merge pantries):" << merged;

    // - : remove an ingredient by name
    Pantry trimmed = p2 - string("Sugar");
    cout << "- (remove Sugar):" << trimmed;

    // == : same owner?
    Pantry sameName("Mama's Kitchen", 0.0);
    cout << "== (same owner?)    : " << (p2 == sameName ? "Yes" : "No") << "\n";
    cout << "== (different?)     : " << (p2 == p1 ? "Yes" : "No") << "\n";

    // < : fewer items?
    cout << "<  (p1 < p2?)       : " << (p1 < p2 ? "Yes (fewer items)" : "No") << "\n";

    // ══════════════════════════════════════
    // 6. REMOVE INGREDIENT
    // ══════════════════════════════════════
    line("Remove Ingredient");
    p2.removeIngredient("Butter");
    cout << p2;

    return 0;
}